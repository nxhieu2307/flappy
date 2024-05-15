#ifndef MUSIC_H
#define MUSIC_H

#include <SDL_mixer.h>
#include <string>

class Sound {
public:
    Sound();
    ~Sound();


    void loadSound(const char* path);

    void Close();
private:
    Mix_Chunk* Music;
};

#endif // MUSIC_H
