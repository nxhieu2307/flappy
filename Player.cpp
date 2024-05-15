#include <iostream>
#include "Player.h"

void Player::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), angle, NULL, SDL_FLIP_NONE);
	}
//	SDL_RenderCopyEx()
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), angle, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), angle, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}

bool Player::JumpState()
{
    return inJump;
}
void Player::Gravity()
{
    if(JumpState())
    {
        speed += gravity;
        jumpHeight = jumpHeight + speed;
        Ypos = Ypos + jumpHeight;
        setDest(60 , Ypos , 60 , 42);
        if(jumpHeight > 0)
        {
            inJump = false;
            jumpHeight = -10;
        }
        angle = -speed * 15;

    }
    else
    {
     //   fall_speed = fall_speed + fall_gravity;
        Ypos = Ypos + fall_speed;
        angle = fall_speed*10;
        setDest(60 , Ypos , 60 , 42);
    }
}

void Player::Jump()
{
    GetJumptime();
    if(jumpTimer - lastJump > 16 )
    {
        speed=0;
        //fall_speed=0;
        inJump = true;
        lastJump = jumpTimer;
    }
    else Gravity();
}
void Player::GetJumptime()
{
    jumpTimer = SDL_GetTicks();
}



void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
    Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
    Tex2 = TextureManager::Texture(address, ren);
}
void Player::Reset()
{
    animationTimer = 0;
    gravity = 0.2;
    fall_gravity = 0.1;
    Ypos=256;
    speed=0;
    fall_speed = 5;
    inJump=0;
    jumpHeight=-10;
    jumpTimer=0;
    lastJump=0;
    setSrc(0,0,34,24);
    setDest(60,100,34,24);
}
