

#include"Gameloop.h"


GameLoop* g = new GameLoop();

int main(int argc, char *argv[])
{

    srand(time(NULL));
    double first=0;
    double last=0;
    g->Init();
    Sound bgmusic;
    bgmusic.loadSound("soundef/bgmusic.mp3");
    g->Highscore();
    do
    {
        g->setStartState(0);
        g->MainMenu();

        while(g->getGameState())
        {
            if(!g->getPauseState())
            {

                g->Event();
                Mix_Resume(-1);
                g->Update();
                g->Render();
                first = SDL_GetTicks();
                if(first - last < 16.7)
                {
                    SDL_Delay(16.7 - (first - last));
                }

                last = first;
            //    cout << "asd ";
            }
            else
            {
                Mix_Pause(-1);
                g->Pause();
                g->Event();
            }
        }
        g->Endgame();


    }
    while(g->getStartState());
    bgmusic.Close();
    g->Clear();
    return 0;
}
