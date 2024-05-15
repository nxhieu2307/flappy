#include "Base.h"

void Base::BaseUpdate1()
{

    if(distance1 <= -800) distance1=0;
    else
    {
        distance1--;
        setDest(distance1 , 550 , 800 , 90);
    }
}
void Base::BaseUpdate2()
{

    if(distance2 <= 0) distance2 = 799;
    else
    {
        distance2--;
        setDest(distance2 , 550 , 800 , 90);
    }
}
void Base::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}
