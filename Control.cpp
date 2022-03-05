#include"Control.h"

#include<iostream>
Control::Control()
{
    window = NULL;
    renderer = NULL;
    Continue = true;

    Bird.setSrc(0, 0, 28, 38);
	Bird.setDest(0, HEIGHT/2, 28, 38);

	Mess.setSrc(0,0,600,400);
	Mess.setDest(200,0,600,400);

	Background.setSrc(0,0,600,800);
	Background.setDest(0,0,600,800);
	Time = 0;
};


void Control::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window  = SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
    renderer=SDL_CreateRenderer(window,-1,0);

    Bird.CreateTexture1("Image/yellowbird1.png", renderer);
    Bird.CreateTexture2("Image/yellowbird2.png", renderer);
    Bird.CreateTexture3("Image/yellowbird3.png", renderer);

    Background.CreateTexture("Image/background.png", renderer);
    Mess.CreateTexture("Image/message.png",renderer);
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

void Control::Event()
{
	SDL_PollEvent(&event);
	    Bird.GetJumpTime();

	if (event.type == SDL_QUIT) Continue = false;

    if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
		{
			if (!Bird.JumpState()) Bird.Jump();else Bird.Gravity();
		}else Bird.Gravity();
	}
	else Bird.Gravity();

}



void Control::Render()
{
    Time++;

    if(Time<100)
    {
        SDL_RenderClear(renderer);
        Background.Render(renderer);
        Mess.Render(renderer);
        Bird.Render(renderer);
        SDL_RenderPresent(renderer);
    }
    else
    {
        SDL_RenderClear(renderer);
        Background.Render(renderer);
        Bird.Render(renderer);
        SDL_RenderPresent(renderer);
    }
}
