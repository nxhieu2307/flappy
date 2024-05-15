
#include "EndWindow.h"

EndWindow::EndWindow():restart{false}{}


void EndWindow::Initialize(SDL_Renderer* ren)
{
	endBackground.CreateTexture("img/EndGame.png", ren);
}

int EndWindow::EventHandling(SDL_Event& e)
{
    SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if ( (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 250 && e.motion.x < 550 && e.motion.y > 450 && e.motion.y < 530) || e.key.keysym.sym == SDLK_SPACE)
	{
		restart = true;
	}
	return 0;

}

void EndWindow::Render(SDL_Renderer* ren)
{
	endBackground.Render(ren);
}
bool EndWindow::getRestart()
{
	return restart;
}

void EndWindow::setRestart( bool s){
	restart=s;
}
EndWindow::~EndWindow()
{
	restart = false;
}
