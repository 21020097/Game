#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "MainMenu.h"
#include "Player.h"
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

    Player Bird;
    long long Time  = 0;
    Object Background ;
    Object Mess;

public:
    Control();
    bool getContinue();
    void Init();
    void Event();
    void Update();
    void sendmess();
    void Render();
    void Clear();

    void MainMenu();
};
