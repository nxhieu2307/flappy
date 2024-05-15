#include "TextManager.h"
using namespace std;
void TextManager::CreateFont(const char* path, int size)
{
    font = TTF_OpenFont(path, size);
    if (font == nullptr)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Load font %s", TTF_GetError());
    }

}

void TextManager::Text(string Text, int r, int g, int b, SDL_Renderer* ren)
{
    char* Txt = new char[Text.size() + 1];
    std::copy(Text.begin(), Text.end(), Txt);
    Txt[Text.size()] = '\0';
    SDL_Color color = { r, g, b, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, Txt, color);
    if (textSurface == NULL)
    {
        cout << TTF_GetError() << endl;
    }
    CreateTexture(textSurface,ren);
    SDL_FreeSurface(textSurface);
    delete Txt;
    Txt = 0;
}

void TextManager::CreateTexture(SDL_Surface* sur,SDL_Renderer* ren)
{
    fontTexture = SDL_CreateTextureFromSurface(ren, sur);
}

void TextManager::Render(SDL_Renderer* ren, int x, int y)
{
    TextRect.x = x, TextRect.y = y;
    SDL_QueryTexture(fontTexture, NULL, NULL, &TextRect.w, &TextRect.h);
    SDL_RenderCopy(ren, fontTexture, NULL, &TextRect);
}

void TextManager::CloseFont()
{
    TTF_CloseFont(font);
}
