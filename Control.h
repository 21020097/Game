#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "MainMenu.h"
#include<iostream>

class Control
{
private:
    const int HEIGHT = 600;
    const int WIDTH = 800;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    bool Continue;
    MainMenu Menu;


public:
    Control();
    bool getContinue();
    void Init();
    void Event();
    void Update();
    void Clear();

    void MainMenu();
};
