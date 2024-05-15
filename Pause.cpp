
#include"Pause.h"

void Pausescreen::Initialize(SDL_Renderer* ren)
{
    pauseBackground.CreateTexture("img/pause.png" , ren);
}

void Pausescreen::Render(SDL_Renderer* ren)
{
    pauseBackground.Render(ren);
}
