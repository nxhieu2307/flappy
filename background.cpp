#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
    SDL_Rect srca = getSrc();
	SDL_Rect destb = getDest();
    SDL_RenderCopy(ren , getTexture(), &srca, &destb);
}
