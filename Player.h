

#ifndef _PLAYER__H
#define _PLAYER__H
#include "Object.h"

class Player : public Object
{
private:
    int animationTimer = 0;
    double gravity = 0.2;
    double fall_gravity = 0.1;
    double Ypos = 256;
    double speed = 0;
    double fall_speed = 5;
    bool inJump = 0;
    double jumpHeight= -10;
    double jumpTimer;
    double lastJump = 0;
    double angle=0;
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;


public:
    void Gravity();
    void GetJumptime();
    void Jump();
    bool JumpState();
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void CreateTexture2(const char* address, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    void Reset();
};


#endif
