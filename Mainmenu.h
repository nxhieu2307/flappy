
#ifndef _MAINMENU__H
#define _MAINMENU__H
#include<SDL.h>
#include<SDL_image.h>
#include "Background.h"

//Main Screen
class MainMenu{
    private:
        bool isClicked;
        Background menuBackground;
    public:
        MainMenu();
        ~MainMenu();
        void Initialize(SDL_Renderer* ren);
        int EventHandling(SDL_Event& e);
        void Render(SDL_Renderer* ren);
        bool getClicked();


};
#endif
