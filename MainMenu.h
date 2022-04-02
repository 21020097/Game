/*
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include <stdio.h>
#include <string>
#include "Object.h"
#include "Player.h"

class MainMenu
{
private:
    bool isClicked;
    SDL_Texture* menuBackGround;

    SDL_Texture* start;

    SDL_Texture* started;

    Object rectstart;

    SDL_Texture* texBird[3];

    Object Bird;

    bool isMainMenu;


public:
    MainMenu();
    ~MainMenu();

    void Init(SDL_Renderer* ren);
    bool getisMainMenu()
    {
        return isMainMenu;
    }
    int EventHandling(SDL_Event&e,SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    bool getClicked();
};
*/
