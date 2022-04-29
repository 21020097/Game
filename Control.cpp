#include"Control.h"
#include<bits/stdc++.h>

Control::Control()
{
    window = NULL;
    renderer = NULL;
    Exit = false;
    Menu = true ;
    Mix  = true ;
    Over = false;
    isOptions = false;
    score =0 ;

    New.setSrc(0,0,17,17);
    New.setDest(350,300,20,40);

	Background.setSrc(0,0,800,500);
	Background.setDest(0,0,800,500);

    play.setDest(150,400,80,200);
    play.setSrc(0,0,170,390);
    play_ed.setDest(150,400,80,200);
    play_ed.setSrc(0,0,170,390);

    Options.setDest(150,500,80,200);
    Options.setSrc(0,0,170,390);
    Options_ed.setDest(150,500,80,200);
    Options_ed.setSrc(0,0,170,390);

    exit.setDest(150,600,80,200);
    exit.setSrc(0,0,170,390);
    exit_ed.setDest(150,600,80,200);
    exit_ed.setSrc(0,0,170,390);

    Back.setDest(150,700,80,200);
    Back.setSrc(0,0,170,390);
    Back_ed.setDest(150,700,80,200);
    Back_ed.setSrc(0,0,170,390);

    Bird.setSrc(0,0,12,17);
    Bird.setDest(225,300,40,50);

    Bird1.setSrc(0,0,12,17);
    Bird1.setDest(225,400,40,50);

    Bird2.setSrc(0,0,12,17);
    Bird2.setDest(225,500,40,50);

    Bird3.setSrc(0,0,12,17);
    Bird3.setDest(225,600,40,50);



    base_on.setSrc(0,0,24,89);
    base_on.setDest(0,0,150,500);

    mix_on.setDest(450,750,45,45);
    mix_on.setSrc(0,0,160,160);

    mix_off.setDest(450,750,45,45);
    mix_off.setSrc(0,0,160,160);

    mess.setSrc(0,0,50,60);
    mess.setDest(150,300,200,200);

    rectTop.setSrc(0,0,500,500);
    rectBottom.setSrc(0,0,500,500);

    gameover.setSrc(0,0,42,192);
    gameover.setDest(0,0,200,500);

    replay.setDest(40,600,80,200);
    replay.setSrc(0,0,170,390);
    replay_ed.setDest(40,600,80,200);
    replay_ed.setSrc(0,0,170,390);

    Quit   .setSrc(0,0,167,384);
    Quit_ed.setSrc(0,0,167,384);
    Quit.setDest(260,600,80,200);
    Quit_ed.setDest(260,600,80,200);

    backgroundscore.setSrc(0,0,282,444);
    backgroundscore.setDest(80,250,200,340);

    Coin.newDest(10,10,40,40);
}

bool Control::getExit()
{
    return Exit;
}

bool Control::getMix()
{
    return Mix;
}

bool Control::getOptions()
{
    return isOptions;
}

bool Control::getOver()
{
    return Over;
}

int Control::getscore()
{
    return score;
}


bool Control::in(double x,double y,Node r)
{
    return (r.x+5<x&&x<r.x+r.w-5  && r.y+5<y&&y<r.y+r.h-5);
}

bool Control::Check(double x,double y,double h,double w)
{
    double x1 = x   ,y1 = y;
    double x2 = x+w ,y2 = y;
    double x3 = x+w ,y3 = y+h;
    double x4 = x   ,y4 = y+h;
    if(y1<0||y1>800) return false;
    if(y2<0||y2>800) return false;
    if(y3<0||y3>800) return false;
    if(y4<0||y4>800) return false;
    for(int i=0;i<5;++i)
    {
        if(in(x1,y1,Top[i])||in(x1,y1,Bottom[i])) return false ;
        if(in(x2,y2,Top[i])||in(x2,y2,Bottom[i])) return false ;
        if(in(x3,y3,Top[i])||in(x3,y3,Bottom[i])) return false ;
        if(in(x4,y4,Top[i])||in(x4,y4,Bottom[i])) return false ;
    }
    return true;
}

bool Control::Check2(double x,double y,double h,double w)
{
    double x1 = x   ,y1 = y;
    double x2 = x+w ,y2 = y;
    double x3 = x+w ,y3 = y+h;
    double x4 = x   ,y4 = y+h;

    if(in(x1,y1,coinCheck)) return false ;
    if(in(x2,y2,coinCheck)) return false ;
    if(in(x3,y3,coinCheck)) return false ;
    if(in(x4,y4,coinCheck)) return false ;

    return true;
}


void Control::Init()
{
    window  = SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,NULL);
    renderer= SDL_CreateRenderer(window,-1,0);

    srand(time(0));

    const char* path_background = (rand()%2==0 ? "Image/background_night.png" : "Image/background_day.png");
    Background.CreateTexture(path_background,renderer);

    play.CreateTexture("Image/play.png",renderer);
    play_ed.CreateTexture("Image/play_ed.png",renderer);

    Options.CreateTexture("Image/Options.png",renderer);
    Options_ed.CreateTexture("Image/Options_ed.png",renderer);

    exit.CreateTexture("Image/exit.png",renderer);
    exit_ed.CreateTexture("Image/exit_ed.png",renderer);

    Bird.CreateTexture1("Image/bird_orange_0.png",renderer);
    Bird.CreateTexture2("Image/bird_orange_1.png",renderer);
    Bird.CreateTexture3("Image/bird_orange_2.png",renderer);


    Bird1.CreateTexture1("Image/bird_orange_0.png",renderer);
    Bird1.CreateTexture2("Image/bird_orange_1.png",renderer);
    Bird1.CreateTexture3("Image/bird_orange_2.png",renderer);


    Bird2.CreateTexture1("Image/bird_red_0.png",renderer);
    Bird2.CreateTexture2("Image/bird_red_1.png",renderer);
    Bird2.CreateTexture3("Image/bird_red_2.png",renderer);


    Bird3.CreateTexture1("Image/bird_blue_0.png",renderer);
    Bird3.CreateTexture2("Image/bird_blue_1.png",renderer);
    Bird3.CreateTexture3("Image/bird_blue_2.png",renderer);

    base_on.CreateTexture("Image/label_flappy_bird.png",renderer);

    mix_off.CreateTexture("Image/mix_off.png",renderer);
    mix_on.CreateTexture("Image/mix_on.png",renderer);

    rectTop.CreateTexture("Image/pipe_Above.png",renderer);
    rectBottom.CreateTexture("Image/pipe_Below.png",renderer);

    Coin.CreateTexture("Image/coin.png",renderer);
    poinCoin.CreateTexture("Image/coin.png",renderer);

    mess.CreateTexture("Image/mess.png",renderer);

    gameover.CreateTexture("Image/gameover.png",renderer);

    replay.CreateTexture("Image/replay.png",renderer);
    replay_ed.CreateTexture("Image/replay_ed.png",renderer);

    Back.CreateTexture("Image/Back.png",renderer);
    Back_ed.CreateTexture("Image/Back_ed.png",renderer);

    backgroundscore.CreateTexture("Image/score.png",renderer);

    Quit   .CreateTexture("Image/Quit.png",renderer);
    Quit_ed.CreateTexture("Image/Quit_ed.png",renderer);

    New.CreateTexture("Image/new.png",renderer);

    jump        = Mix_LoadWAV("Mix/sfx_wing.wav");
    mouse_click = Mix_LoadWAV("Mix/mouse_click.wav");
    music       = Mix_LoadWAV("Mix/ingame.wav");
    diebird     = Mix_LoadWAV("Mix/sfx_hit.wav");
    getScore    = Mix_LoadWAV("Mix/sfx_point.wav");
}

void Control::Gen()
{
    srand(time(0));
    for(int i=0;i<5;++i)
    {
        int temp = rand()%200;
        Bottom[i].flag=Top[i].flag=0;
        Top[i].w=Bottom[i].w=100;

        Top[i].h=200+temp;
        Top[i].y=0;

        Bottom[i].y=400+temp;
        Bottom[i].h=800-Bottom[i].y;

    }

    Top[0].x=Bottom[0].x=500;
    for(int i=1;i<5;++i)
    {
        int temp2 = rand()%100;
        Top[i].x    = Top[i-1].x    + 200 + temp2;
        Bottom[i].x = Bottom[i-1].x + 200 + temp2;
    }

}

void Control::Update()
{
    for(int i=0;i<5;++i) Top[i].x-=2,Bottom[i].x-=2;

    for(int i=0;i<5;++i)
    {
        if(Top[i].x<=225&&225<=Top[i].x+100&&!Top[i].flag)
        {
            double cx = Top[i].x+25;
            double cw = 45;
            double cy = Top[i].h + (Bottom[i].y-Top[i].h)/2-25;
            double ch = 45;
            coinCheck.x = cx;
            coinCheck.y = cy;
            coinCheck.h = ch;
            coinCheck.w = cw;
            if(!Check2(225,Bird.getYpos(),40,50))
            {
                Top[i].flag=1,score++;
                if(Mix) Mix_PlayChannel(-1,getScore,0);
            }
        }
    }
    if(Top[0].x<-100)
    {
        for(int i=1;i<5;++i) Top[i-1]=Top[i],Bottom[i-1]=Bottom[i];
        srand(time(0));
        int temp1 = rand()%80 - rand()%80;
        int temp2 = rand()%80 - rand()%80;

        Top[4].x =Top[3].x+200;
        Bottom[4].x=Bottom[3].x+200;
        Top[4].w=Bottom[4].w=100;

        Top[4].y =0;
        Top[4].h =200+temp1;

        Bottom[4].y = 400 + temp2;
        Bottom[4].h=800-Bottom[4].y;
    }
}

void Control::Event()
{
    Bird.GetJumpTime();
	SDL_PollEvent(&event);

	if(event.type == SDL_QUIT) Exit = true;


	if(Menu)
    {
        // Off Mix
        if(event.motion.x>=450 && event.motion.x<=500 && event.motion.y>=750 && event.motion.y<=800&&event.type == SDL_MOUSEBUTTONDOWN )
        {
            Mix = !Mix;
            SDL_Delay(200);
        }

        //  Click to Play
        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=150&&event.motion.x<=350 &&event.motion.y>=400&&event.motion.y<=480)
        {
            SDL_RenderClear(renderer);
            Background.Render(renderer);
            Bird.Render(renderer,0);
            Options.Render(renderer);
            play_ed.Render(renderer);
            exit.Render(renderer);
            if(Mix) mix_on.Render(renderer);
            else    mix_off.Render(renderer);
            SDL_RenderPresent(renderer);

            Menu = false;
            if(Mix)
            {
                Mix_PlayChannel(-1,music,-1);
                Mix_PlayChannel(-1,mouse_click,0);
            }
            SDL_Delay(200);
        }

        // Click to Options
        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=150&&event.motion.x<=350 &&event.motion.y>=500&&event.motion.y<=580)
        {
            SDL_RenderClear(renderer);
            Background.Render(renderer);
            base_on.Render(renderer);
            Bird.Render(renderer,0);
            play.Render(renderer);
            Options_ed.Render(renderer);
            exit.Render(renderer);
            if(Mix) mix_on.Render(renderer);
            else    mix_off.Render(renderer);
            SDL_RenderPresent(renderer);

            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            isOptions = true;
            Menu      = false;
            SDL_Delay(200);
        }

        // Click to Exit
        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=150&&event.motion.x<=350 &&event.motion.y>=600&&event.motion.y<=680)
        {
            SDL_RenderClear(renderer);
            Background.Render(renderer);
            Bird.Render(renderer,0);
            play.Render(renderer);
            Options.Render(renderer);
            exit_ed.Render(renderer);
            if(Mix) mix_on.Render(renderer);
            else    mix_off.Render(renderer);
            SDL_RenderPresent(renderer);

            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            Menu = false;
            Exit = true ;
            SDL_Delay(200);
        }
    }
    else
    if(isOptions)
    {

        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=225&&event.motion.x<=225+50 &&event.motion.y>=400&&event.motion.y<=440)
        {
            Menu = true; isOptions = false;

            Bird.CreateTexture1("Image/bird_orange_0.png",renderer);
            Bird.CreateTexture2("Image/bird_orange_1.png",renderer);
            Bird.CreateTexture3("Image/bird_orange_2.png",renderer);
            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            SDL_Delay(200);
        }

        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=225&&event.motion.x<=225+50 &&event.motion.y>=500&&event.motion.y<=540)
        {
            Menu = true; isOptions = false;

            Bird.CreateTexture1("Image/bird_red_0.png",renderer);
            Bird.CreateTexture2("Image/bird_red_1.png",renderer);
            Bird.CreateTexture3("Image/bird_red_2.png",renderer);

            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            SDL_Delay(200);
        }

        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=225&&event.motion.x<=225+50 &&event.motion.y>=600&&event.motion.y<=640)
        {
            Menu = true;
            isOptions = false;
            Bird.CreateTexture1("Image/bird_blue_0.png",renderer);
            Bird.CreateTexture2("Image/bird_blue_1.png",renderer);
            Bird.CreateTexture3("Image/bird_blue_2.png",renderer);

            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            SDL_Delay(200);
        }

        if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=150&&event.motion.x<=150+200 &&event.motion.y>=700&&event.motion.y<=780)
        {
            Menu = true;
            isOptions = false ;
            SDL_RenderClear(renderer);
            Background.Render(renderer);
            Bird1.Render(renderer,0);
            Bird2.Render(renderer,0);
            Bird3.Render(renderer,0);
            Back_ed.Render(renderer);
             SDL_RenderPresent(renderer);
            if(Mix) Mix_PlayChannel(-1,mouse_click,0);
            SDL_Delay(200);
        }
    }
    else
    {
        if(Over)
        {
            best.update_bestscore(score);
            if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=260&&event.motion.x<=460 &&event.motion.y>=600&&event.motion.y<=680)
            {
                SDL_RenderClear(renderer);
                Background.Render(renderer);
                backgroundscore.Render(renderer);

                Bird1.Render(renderer,0);
                Bird2.Render(renderer,0);
                Bird3.Render(renderer,0);

                Back_ed.Render(renderer);
                if(Mix) mix_on.Render(renderer);
                else    mix_off.Render(renderer);
                SDL_RenderPresent(renderer);
                if(Mix) Mix_PlayChannel(-1,mouse_click,0);
                Exit = true ;
                SDL_Delay(200);
            }

            if(event.type == SDL_MOUSEBUTTONDOWN && event.motion.x>=40&&event.motion.x<=240 &&event.motion.y>=600&&event.motion.y<=680)
            {
                SDL_RenderClear(renderer);
                Background.Render(renderer);
                backgroundscore.Render(renderer);
                replay_ed.Render(renderer);
                gameover.Render(renderer);
                Quit.Render(renderer);


                if(Mix) mix_on.Render(renderer);
                else    mix_off.Render(renderer);
                SDL_RenderPresent(renderer);


                Menu = true;
                Over = false ;

                Gen();
                Bird.Reset();
                Bird.setDest(225,300,40,50);
                Mix_HaltChannel(-1);
                score = 0;
                if(Mix) Mix_PlayChannel(-1,mouse_click,0);
                SDL_Delay(500);
            }
        }
        else
        {
            if (event.type == SDL_KEYDOWN||event.type==SDL_MOUSEBUTTONDOWN)
            {
                if (event.key.keysym.sym == SDLK_UP||event.type==SDL_MOUSEBUTTONDOWN)
                {
                    if (!Bird.JumpState())
                    {
                        Bird.Jump();
                        if(Mix) Mix_PlayChannel(-1,jump,0);
                    }
                    else Bird.Gravity();
                }else Bird.Gravity();
            }
            else Bird.Gravity();

            Update();
            if(!Check(225,Bird.getYpos(),40,50))
            {
                if(Mix) Mix_PlayChannel(-1,diebird,0);
                Over = 1;
            }
        }
    }
}



void Control::Render()
{
    SDL_RenderClear(renderer);
    Background.Render(renderer);

    if(Menu)
    {
        Bird.Render(renderer,0);
        base_on.Render(renderer);
        play.Render(renderer);
        Options.Render(renderer);
        exit.Render(renderer);
        if(Mix) mix_on.Render(renderer);
        else    mix_off.Render(renderer);

    }
    else
    if(isOptions)
    {
        base_on.Render(renderer);
        Bird1.Render(renderer,0);
        Bird2.Render(renderer,0);
        Bird3.Render(renderer,0);
        Back.Render(renderer);

        if(Mix) mix_on.Render(renderer);
        else    mix_off.Render(renderer);
    }
    else
    {
        if(Bird.JumpState()) Bird.Render(renderer,-30);
        else                 Bird.Render(renderer, 30);
        for(int i=0;i<5;++i)
        {
            rectTop.setDest(Top[i].x,Top[i].y,Top[i].h,Top[i].w);
            rectBottom.setDest(Bottom[i].x,Bottom[i].y,Bottom[i].h,Bottom[i].w);
            rectTop.Render(renderer);
            rectBottom.Render(renderer);

            if(!Top[i].flag)
            {
                double cx = Top[i].x+30;
                double cw = 50;
                double cy = Top[i].h + (Bottom[i].y-Top[i].h)/2-30;
                double ch = 50;
                poinCoin.newDest(cx,cy,ch,cw);
                poinCoin.Render(renderer);
            }

        }


        if(Over)
        {
            replay.Render(renderer);
            Quit.Render(renderer);
            gameover.Render(renderer);
            backgroundscore.Render(renderer);
            poin.Render_Score(renderer,score);
            poin.Render_Best(renderer,best.get_bestscore());
            if(best.get_bestscore()==score) New.Render(renderer);
        }
        else
        {
            if(!score) mess.Render(renderer);
        }

        Coin.Render(renderer);
        poin.Render(renderer,score);
    }

    SDL_RenderPresent(renderer);
}

void Control::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
