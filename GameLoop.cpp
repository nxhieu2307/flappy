#include"GameLoop.h"

GameLoop::GameLoop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
    // source dimension
    p.setSrc(0,0,34,24);

    b.setSrc(0,0,800,600);
    // Destination dimension
    p.setDest(10,20,34,24);
    b.setDest(0,0,800,600);
}


void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

bool GameLoop::getGameState()
{
    return GameState;
}

void GameLoop::Init()
{


  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    if(renderer)
    {
        cout << "asd";
        GameState = true;
        p.CreateTexture("img/bird.png" , renderer);
        b.CreateTexture("img/backgroundd.png" , renderer);
        //background = TextureManager::Texture("img/backgroundd.png" , renderer);
    }
}

void GameLoop::Event()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        GameState = false;
    }

}

void GameLoop::Update()
{


}
void GameLoop::Render()
{

    SDL_RenderClear(renderer);
   // SDL_RenderCopy(renderer, background , &srcbackground , &srcbackground);
    b.Render(renderer);
	p.Render(renderer);
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}
