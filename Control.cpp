#include"Control.h"

#include<iostream>
Control::Control()
{
    window = NULL;
    renderer = NULL;
    Continue = false ;
};


void Control::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window  = SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
    renderer=SDL_CreateRenderer(window,-1,0);
}


void Control::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool Control::getContinue()
{
    return Continue;
}

void Control::MainMenu()
{
    Menu.Init(renderer);
    while(!Menu.getClicked())
    {
        if(Menu.EventHandling(event) == -1)
        {
            Continue = false ;
            break ;
        }
        Menu.Render(renderer);
    }
}
