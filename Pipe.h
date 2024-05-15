
#ifndef _PIPE__H
#define _PIPE__H
#include "Object.h"

const int PIPE_MIN_HEIGHT = 170; // Minimum height of the pipe
const int PIPE_MAX_HEIGHT = 320; // Maximum height of the pipe

static int PipePos[4] , PipeHeight[4] , PipeHeight2[4];


class Pipe : public Object
{
private:
public:
    int left_behind = 0;
    int pipeH=320 , pipeW=60 , space=170;
    Pipe();
    Pipe(int i);
    int getHeight();
    void Update1(int i);
    void Update2(int i);
    void SpaceScore(int i);

    void Render(SDL_Renderer* ren);

};

#endif
