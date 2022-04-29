#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "MainMenu.h"
#include "Player.h"
#include<bits/stdc++.h>
#include"Coin.h"
#include"Score.h"
#include"bestscore.h"
class Control
{
private:
    const int HEIGHT = 800;
    const int WIDTH = 500;

    bool Exit;
    bool Menu;
    bool Mix;
    bool Over;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    Object Background;
    Object play,play_ed;
    Object exit,exit_ed;
    Object mix_on,mix_off;
    Object base_on;
    Object Quit,Quit_ed;
    Object mess;
    Object Back,Back_ed;
    Object New;

    Player Bird,Bird1,Bird2,Bird3;
    Mix_Chunk *jump,*mouse_click;
    Mix_Chunk *music;
    Mix_Chunk *diebird;
    Mix_Chunk *getScore;

    Coin Coin,poinCoin;

    int score;

    Score poin;

    struct Node
    {
        double x,y,h,w;
        bool flag;
    }Top[5],Bottom[5],coinCheck;
    Object rectTop,rectBottom;

    Object gameover;
    Object replay,replay_ed;
    Object Options,Options_ed;
    bool isOptions;
    bestscore best;

    Object backgroundscore;
public:
    Control();
    void Init();
    void Event();
    void Render();

    bool getExit();
    bool getMix();
    bool getOver();

    bool getOptions();

    void Clear();

    bool Check(double x,double y,double h,double w);
    bool Check2(double x,double y,double h,double w);
    bool in(double x,double y,Node r);
    void Gen();
    void Update();

    int getscore();
};
