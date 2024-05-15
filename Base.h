

#ifndef _BASE__H
#define _BASE__H
#include "Object.h"

class Base : public Object
{
private:
    int distance1 =0;
    int distance2 =0;

public:
	void Render(SDL_Renderer* ren);
	void BaseUpdate1();
    void BaseUpdate2();

};
#endif
