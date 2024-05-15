#include "Pipe.h"
#include<bits/stdc++.h>
using namespace std;

Pipe :: Pipe()
{
    pipeW = 60;
    pipeH = 320;
    space = 170;
}
Pipe :: Pipe(int i)
{


    PipePos[i] = 200 + (i*200);
    PipeHeight[i] = rand() % (320 - 170 + 1) + 170;
    PipeHeight2[i] = PipeHeight[i] + space;
    setDest(PipePos[i], PipeHeight[i] - pipeH, pipeW, pipeH);
}


void Pipe::Update1(int i) // upper
{
    if(PipePos[i] <= -pipeW)
    {
        PipeHeight[i] = rand() % (320 - 170 + 1) + 170;
        left_behind=0;
        PipePos[i] = 820;
    }
    else
    {
        PipePos[i]--;

        setSrc(0 , 0 , 60 , 320);
        setDest(PipePos[i], PipeHeight[i] - pipeH, pipeW, pipeH);
    }


}

void Pipe::Update2(int i)
{
    PipeHeight2[i] = PipeHeight[i] + space;
    setSrc(0, 0, 60, 320);
    setDest(PipePos[i], PipeHeight2[i], pipeW, pipeH);

}

void Pipe::SpaceScore(int i)
{
    setSrc(0, 0, 0, 0);

    setDest(PipePos[i] + 20, PipeHeight[i], 3, space);
}
void Pipe::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

