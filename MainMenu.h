#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include <stdio.h>
#include <string>

class MainMenu
{
private:
    bool isClicked;
    SDL_Texture* menuBackGround;
public:
    MainMenu();
    ~MainMenu();

    void Init(SDL_Renderer* ren);

    int EventHandling(SDL_Event&e);
    void Render(SDL_Renderer* ren);
    bool getClicked();
};
