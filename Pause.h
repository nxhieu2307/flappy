
#ifndef _PAUSE__H
#define _PAUSE__H

#include"Background.h"

class Pausescreen
{
public:

    Background pauseBackground;

    void Initialize(SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
};
#endif
