#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include "GenTexture.h"
#include<iostream>
class Control
{
private:
    const int HEIGHT = 640;
    const int WIDTH = 800;
    // Con trỏ cửa sổ
    SDL_Window* window;

    // Con trỏ để vẽ
    SDL_Renderer* renderer;

    // Con trỏ thể hiện cho sự kiện (chuột, bàn phím, toạ độ chuột và nút bàn phím
    SDL_Event event;

    // Có tiếp tục game hay không
    bool Continue;
    bool isMenu;


    SDL_Texture* Background;
    SDL_Texture* Menu;

    // Con chim
    SDL_Rect srcPlayer,destPlayer;
    SDL_Texture* Bird1;
    SDL_Texture* Bird2;
    SDL_Texture* Bird3;
public:
    Control();
    bool getisMenu();
    bool getContinue();

    void Init();
    void Event();
    void Update();
    void Render_Background();
    void Render_Menu();
    void Clear();
};
