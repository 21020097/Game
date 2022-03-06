#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include <stdio.h>
#include <string>
#include "Object.h"
class MainMenu
{
private:
    bool isClicked;
    SDL_Texture* menuBackGround;
    Object glass;
public:
    MainMenu();
    ~MainMenu();

    void Init(SDL_Renderer* ren);

    int EventHandling(SDL_Event&e,SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    bool getClicked();
};
