

#ifndef _BACKGROUND__H
#define _BACKGROUND__H
#include "Object.h"

class Background : public Object
{
private:
    SDL_Texture* Tex1;
public:
	void Render(SDL_Renderer* ren);
    void CreateTexture1(const char* address, SDL_Renderer* ren);

};
#endif
