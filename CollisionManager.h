
#ifndef _COLLISIONMANAGER__H
#define _COLLISIONMANAGER__H
#include<SDL.h>
#include<SDL_image.h>

class CollisionManager
{
public:
	static bool CheckCollision(SDL_Rect* A, SDL_Rect* B);
};

#endif
