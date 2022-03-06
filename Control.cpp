#include"Control.h"
#include<bits/stdc++.h>

Control::Control()
{
    window = NULL;
    renderer = NULL;
    Continue = true;
    isOver = false ;

    Bird.setSrc(0, 0, 28, 38);
    Bird.setDest(200, HEIGHT/2, 28, 38);
	Mess.setSrc(0,0,600,400);
	Mess.setDest(200,0,600,400);

	Over.setSrc(0,0,200,400);
	Over.setDest(200,300,200,400);

	Background.setSrc(0,0,600,800);
	Background.setDest(0,0,600,800);

	BU.setSrc(0,0,400,100);
	BD.setSrc(0,0,400,100);
	Time = 0;

	click = Mix_LoadWAV("Mix/Clicked.wav");
};

void Control::GenBlock()
{
    srand(time(0));
    blockU[0].x = 500;blockU[0].y=0;blockU[0].h=200,blockU[0].w=80;
    blockD[0].x = 500;blockD[0].y=400;blockD[0].h=200,blockD[0].w=80;

    for(int i=1;i<MAXN;++i) blockU[i]=blockU[i-1];
    for(int i=0;i<MAXN;++i) blockU[i].h+=rand()%70;

    for(int i=1;i<MAXN;++i) blockD[i]=blockD[i-1];
    for(int i=0;i<MAXN;++i) blockD[i].y-=rand()%70,blockD[i].h=600-blockD[i].y;

    for(int i=1;i<MAXN;++i)
    {
        int temp =rand()%250;
        blockU[i].x = blockU[i-1].x + 160+temp;
        blockD[i].x = blockD[i-1].x + 160+temp;
    }

}


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
    BU.CreateTexture("Image/pipe_Above.png",renderer);
    BD.CreateTexture("Image/pipe_Below.png",renderer);
    Over.CreateTexture("Image/gameover.png",renderer);
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
        if(Menu.EventHandling(event,renderer) == -1)
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
	if(Bird.getYpos()<=0||Bird.getYpos()>=HEIGHT) isOver=true;
	if (isOver)
    {
        //if(event.type==SDL_MOUSEBUTTONDOWN)
        Continue = false ;
    }

    if (event.type == SDL_KEYDOWN||event.type==SDL_MOUSEBUTTONDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP||event.type==SDL_MOUSEBUTTONDOWN)
		{
		    Mix_PlayChannel( -1,click, 0 );
			if (!Bird.JumpState()) Bird.Jump();else Bird.Gravity();
		}else Bird.Gravity();
	}
	else Bird.Gravity();
}

bool Control::Check(Node a,Node b)
{
    int x1 = a.x  , y1 = a.y,
           u1 = a.x+a.w, v1 = a.y+a.h;

    int x2 = b.x  , y2 = b.y,
        u2 = b.x+b.w, v2 = b.y+b.h;

    if(x1<=x2&&x2<=u1 && y1<=y2&&y2<=v1) return true;

    if(x1<=u2&&u2<=u1 && y1<=y2&&y2<=v1) return true;

    if(x1<=x2&&x2<=u1 && y1<=v2&&v2<=v1) return true;

    if(x1<=u2&&u2<=u1 && y1<=v2&&v2<=v1) return true;

    Node c = a;
    a=b;b=c;

    x1 = a.x  , y1 = a.y, u1 = a.x+a.w, v1 = a.y+a.h;

    x2 = b.x  , y2 = b.y, u2 = b.x+b.w, v2 = b.y+b.h;
    if(x1<=x2&&x2<=u1 && y1<=y2&&y2<=v1) return true;

    if(x1<=u2&&u2<=u1 && y1<=y2&&y2<=v1) return true;

    if(x1<=x2&&x2<=u1 && y1<=v2&&v2<=v1) return true;

    if(x1<=u2&&u2<=u1 && y1<=v2&&v2<=v1) return true;

    return false ;
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
        for(int i=0;i<MAXN;++i)
        {
            blockU[i].x-=3;BU.setDest(blockU[i].x,blockU[i].y,blockU[i].h,blockU[i].w);
            blockD[i].x-=3;BD.setDest(blockD[i].x,blockD[i].y,blockD[i].h,blockD[i].w);
            if(blockD[i].x>=-80&&blockD[i].x<=800)
            {
                Node RECT_BIRD = {Bird.getDest().x,Bird.getDest().y,Bird.getDest().h,Bird.getDest().w};

                BU.Render(renderer),BD.Render(renderer);
                if(Check(RECT_BIRD,blockD[i])||Check(RECT_BIRD,blockU[i])) isOver=true;
            }

        }


        BD.Render(renderer);

        Bird.Render(renderer);
        if(isOver)
        {
            Over.Render(renderer);
        }


        SDL_RenderPresent(renderer);
    }
}
