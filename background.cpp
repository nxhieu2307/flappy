#include "Background.h"

void Background::Render(SDL_Renderer *ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::CreateTexture1(const char* address, SDL_Renderer* ren)
{
    Tex1 = TextureManager::Texture(address, ren);
}
