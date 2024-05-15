#include"GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;

    p.setSrc(0,0,60,42);
    p.setDest(60,100,60,42);

    b.setSrc(0,0,WIDTH,HEIGHT);
    b.setDest(0,0,WIDTH,HEIGHT);

    base1.setSrc(0, 0, 336, 112);
    base2.setSrc(0, 0, 336, 112);

}

void GameLoop::setStartState(bool x)
{
    StartState = x;
}
bool GameLoop::getGameState()
{
    return GameState;
}
bool GameLoop::getPauseState()
{
    return PauseState;
}
bool GameLoop::getStartState()
{
    return StartState;
}
void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void GameLoop::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        logErrorAndExit("CreateRenderer", SDL_GetError());
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                         Mix_GetError() );
    }
    if (TTF_Init() == -1)
    {
        logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                        TTF_GetError());
    }


    if(renderer)
    {

        GameState = true;
        p.CreateTexture("img/bird1.png", renderer);
        p.CreateTexture1("img/bird2.png", renderer);
        p.CreateTexture2("img/bird3.png", renderer);

        b.CreateTexture("img/backgroundd.png", renderer);

        base1.CreateTexture("img/base.png", renderer);
        base2.CreateTexture("img/base.png", renderer);
        for(int i=0 ; i < 4 ; i++)
        {
            pipe1[i] = Pipe(i);
            pipe1[i].CreateTexture("img/pipedown.png", renderer);
            pipe2[i].CreateTexture("img/pipeup.png", renderer);
        }

        score.CreateFont("font/calibrib.ttf", 40);
        highscore.CreateFont("font/calibrib.ttf", 40);


    }


}

void GameLoop::MainMenu()
{
    menu.Initialize(renderer);

    while (!menu.getClicked())
    {
        if (menu.EventHandling(event) == -1)
        {
            GameState = false;
            exit(0);
        }
        SDL_RenderClear(renderer);
        menu.Render(renderer);
        SDL_RenderPresent(renderer);
    }

}
void GameLoop::Endgame()
{
    die_s.loadSound("soundef/die.wav");
    ew.Initialize(renderer);
    while (!ew.getRestart())
    {
        if (ew.EventHandling(event) == -1)
        {
            GameState = false;
            exit(0);
        }
        SDL_RenderClear(renderer);
        ew.Render(renderer);
        string s;
        s =  std::to_string(points);
        score.Text(s, 0, 0, 0, renderer);
        score.Render(renderer, 400, 280);
        string ss;
        ss = std::to_string(best);

        highscore.Text(ss , 0 , 0 , 0 ,renderer);
        highscore.Render(renderer , 400 , 350);

        SDL_RenderPresent(renderer);

    }

    if (ew.getRestart())
    {
        GameState = true;
        StartState = true;
        points=0;
        Reset();
        ew.setRestart(false);

    }

}

void GameLoop::Pause()
{
    Ps.Initialize(renderer);
    SDL_RenderClear(renderer);
    Ps.Render(renderer);
    SDL_RenderPresent(renderer);

}
void GameLoop::Event()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        GameState = false;
    }

    if(event.type == SDL_KEYDOWN)
    {

        if(event.key.keysym.sym == SDLK_UP)
        {
            if(!PauseState)
            {

                if(!p.JumpState())
                {
                    p.Jump();
                    wing_s.loadSound("soundef/wing.wav");
                }

                else
                {
                    p.Gravity();
                }
            }
        }
        else if (event.key.keysym.sym == SDLK_SPACE)
        {
            PauseState = 1-PauseState;
        }
    }
    else
    {
      if(!PauseState)   p.Gravity();

    }

}

void GameLoop::Update()
{
    base1.BaseUpdate1();
    base2.BaseUpdate2();
    pipe1[0].Update1(0);
    pipe1[1].Update1(1);
    pipe1[2].Update1(2);
    pipe1[3].Update1(3);

    pipe2[0].Update2(0);
    pipe2[1].Update2(1);
    pipe2[2].Update2(2);
    pipe2[3].Update2(3);


    string s;
    s = "Score: " + std::to_string(points);
    score.Text(s, 255, 255, 255, renderer);
    getHighscore();

    string ss = "Highscore: " + std::to_string(best);
  //  cout << "best " << best << "\n";
    highscore.Text(ss ,255, 255 , 255 , renderer);

    // cout << points << "\n";
    CollisionDection();
    check_score();


}
void GameLoop::Render()
{

    SDL_RenderClear(renderer);

    b.Render(renderer);

    pipe1[0].Render(renderer);
    pipe1[1].Render(renderer);
    pipe1[2].Render(renderer);
    pipe1[3].Render(renderer);


    pipe2[0].Render(renderer);
    pipe2[1].Render(renderer);
    pipe2[2].Render(renderer);
    pipe2[3].Render(renderer);

    p.Render(renderer);

    base1.Render(renderer);
    base2.Render(renderer);


    score.Render(renderer, 50, 10);
    highscore.Render(renderer, 50, 50);

    SDL_RenderPresent(renderer);

}

void GameLoop::Clear()
{
    score.CloseFont();
    highscore.CloseFont();

    TTF_Quit();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    window = NULL;
    renderer = NULL;

    die_s.Close();
    hit_s.Close();
    wing_s.Close();
    swoosh_s.Close();
    point_s.Close();

}

void GameLoop::CollisionDection()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(CollisionManager::CheckCollision(&p.getDest(), &pipe1[i].getDest()))
        {
            GameState=0;
            hit_s.loadSound("soundef/hit.wav");
        }

    }
    for(int i = 0 ; i < 3 ; i++)
    {
        if(CollisionManager::CheckCollision(&p.getDest(), &pipe2[i].getDest()))
        {
            GameState=0;
            hit_s.loadSound("soundef/hit.wav");
        }

    }

    if(CollisionManager::CheckCollision(&p.getDest(),  &base1.getDest())  || CollisionManager::CheckCollision(&p.getDest(),  &base2.getDest()) )
    {
        GameState=0;
        hit_s.loadSound("soundef/hit.wav");
    }

}

void GameLoop::check_score()
{
    if(GameState)
    {
        for(int i=0 ; i < 3 ; i++)
        {
            if(!pipe1[i].left_behind)
            {
                auto aa = &p.getDest();
                int x1=aa->x;
                int w1=aa->w/3;
                auto bb = &pipe1[i].getDest();
                int x2=bb->x;
                int w2=bb->w;
                if( (x1+w1)  == (x2))
                {
                    points++;
                    pipe1[i].left_behind = 1;
                    point_s.loadSound("soundef/point.wav");
                    break;
                }
            }
        }
    }
}
void GameLoop::Reset()
{
    p.Reset();
    birdDie=0;
    for(int i=0 ; i < 4 ; i++)
    {
        pipe1[i].left_behind=0;
        pipe1[i] = Pipe(i);
        pipe1[i].CreateTexture("img/pipedown.png", renderer);
        pipe2[i].CreateTexture("img/pipeup.png", renderer);
    }
    points=0;
    touchBase=0;
    die_s.Close();
    hit_s.Close();
    wing_s.Close();
    swoosh_s.Close();
    point_s.Close();
}

void GameLoop::getHighscore()
{
    if(points > best)
    {
        best = points;
    }
    fstream file("score.txt");
    file << best;
    file.close();
}
void GameLoop::Highscore()
{
	fstream file("score.txt");
	file >> best;
	file.close();
}
