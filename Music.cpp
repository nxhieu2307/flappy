#include"Music.h"
#include<bits/stdc++.h>
using namespace std;


Sound::Sound()
{
    Music = nullptr;

}
Sound::~Sound()
{
    Music = nullptr;
    Close();
}

void Sound::loadSound(const char* path)
{
    Music = Mix_LoadWAV(path);
    if (Music == nullptr)
    {

               return;
    }
    Mix_PlayChannel(-1 , Music , 0);
    return;

}

void Sound::Close()
{
    if(Music != nullptr) Mix_FreeChunk(Music);
}

