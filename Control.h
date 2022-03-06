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
    const int MAXN =5000;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    bool Continue;
    MainMenu Menu;

    Player Bird;
    long long Time  = 0;
    Object Background ;
    Object Mess;
    Object Over;
    struct Node
    {
        int x,y,h,w;
    }blockU[5000],blockD[5000];
    bool isOver;
    Mix_Chunk *click;
    Object BU,BD;

public:
    Control();
    bool getContinue();
    void Init();
    void Event();
    void Update();
    void sendmess();
    void Render();
    void Clear();
    void GenBlock();
    void MainMenu();
    void GameOver();
    bool Check(Node a,Node b);
};
