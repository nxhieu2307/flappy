#pragma once
#ifndef _ENDWINDOW__H
#define _ENDWINDOW__H

#include"Background.h"


class EndWindow
{
public:
    bool restart=false;
    Background endBackground;
public:
    EndWindow();
    ~EndWindow();
    void Initialize(SDL_Renderer* ren);
    int EventHandling(SDL_Event& e);
    void Render(SDL_Renderer* ren);
    bool getRestart() ;
    void setRestart( bool s);
};
#endif
