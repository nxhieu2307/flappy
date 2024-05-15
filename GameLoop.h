
#ifndef _GAMELOOP__H
#define _GAMELOOP__H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include"TextManager.h"
#include"TextureManager.h"
#include"Music.h"
#include"Background.h"
#include"Player.h"
#include"Pipe.h"
#include"Base.h"
#include"Mainmenu.h"
#include"EndWindow.h"
#include"Pause.h"

#include"CollisionManager.h"

using namespace std;
class GameLoop
{
private:
    Background b;

    Player p;
    Pipe pipe1[4];
    Pipe pipe2[4];
    Base base1 , base2;
    EndWindow ew;
    TextManager score;
    TextManager highscore;
    Pausescreen Ps;
    MainMenu menu;

    Sound wing_s , hit_s , point_s , die_s , swoosh_s;

    bool birdDie=0;
    bool touchBase = 0;
    bool menuclicked=0;
    int points=0;
    int best;
    const int HEIGHT = 600;
    const int WIDTH = 800;
    bool GameState;
    bool StartState;
    bool PauseState;



    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    SDL_Texture* player;
    SDL_Texture* background;
    SDL_Rect srcPlayer, destPlayer;
    SDL_Rect srcbackground;
public:
    GameLoop();
   // ~GameLoop();


    bool getGameState();
    bool getStartState();
    bool getPauseState();
    void setStartState(bool x);

    void MainMenu();
    void Pause();
    void Endgame();

    void Update();
    void Init();
    void Event();
    void Render();
    void Clear();

    void CollisionDection();
    void check_score();

    void Reset();

    void getHighscore();
    void Highscore();


};



#endif
