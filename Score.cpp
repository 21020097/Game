#include"Score.h"

void Score::Render(SDL_Renderer* ren,int Count)
{
    p.setSrc(0,0,50,50);
    int length = 5;
    do
    {
        p.setDest(length*20,10,45,20);
        if(Count%10==0) p.CreateTexture("Image/number_large_0.png",ren);
        if(Count%10==1) p.CreateTexture("Image/number_large_1.png",ren);
        if(Count%10==2) p.CreateTexture("Image/number_large_2.png",ren);
        if(Count%10==3) p.CreateTexture("Image/number_large_3.png",ren);
        if(Count%10==4) p.CreateTexture("Image/number_large_4.png",ren);
        if(Count%10==5) p.CreateTexture("Image/number_large_5.png",ren);
        if(Count%10==6) p.CreateTexture("Image/number_large_6.png",ren);
        if(Count%10==7) p.CreateTexture("Image/number_large_7.png",ren);
        if(Count%10==8) p.CreateTexture("Image/number_large_8.png",ren);
        if(Count%10==9) p.CreateTexture("Image/number_large_9.png",ren);

        p.Render(ren);
        Count/=10;
        length--;
    }while(Count!=0);
}

void Score::Render_Score(SDL_Renderer* ren,int Count)
{
    p2.setSrc(0,0,50,50);
    int length = 5;
    do
    {
        p2.setDest(length*20+100,320,60,20);
        if(Count%10==0) p2.CreateTexture("Image/number_middle_0.png",ren);
        if(Count%10==1) p2.CreateTexture("Image/number_middle_1.png",ren);
        if(Count%10==2) p2.CreateTexture("Image/number_middle_2.png",ren);
        if(Count%10==3) p2.CreateTexture("Image/number_middle_3.png",ren);
        if(Count%10==4) p2.CreateTexture("Image/number_middle_4.png",ren);
        if(Count%10==5) p2.CreateTexture("Image/number_middle_5.png",ren);
        if(Count%10==6) p2.CreateTexture("Image/number_middle_6.png",ren);
        if(Count%10==7) p2.CreateTexture("Image/number_middle_7.png",ren);
        if(Count%10==8) p2.CreateTexture("Image/number_middle_8.png",ren);
        if(Count%10==9) p2.CreateTexture("Image/number_middle_9.png",ren);
        p2.Render(ren);
        Count/=10;
        length--;
    }while(Count!=0);
}

void Score::Render_Best(SDL_Renderer* ren,int Count)
{
    p3.setSrc(0,0,50,50);
    int length = 5;
    do
    {
        p3.setDest(length*20+250,320,30,20);
        if(Count%10==0) p3.CreateTexture("Image/number_middle_0.png",ren);
        if(Count%10==1) p3.CreateTexture("Image/number_middle_1.png",ren);
        if(Count%10==2) p3.CreateTexture("Image/number_middle_2.png",ren);
        if(Count%10==3) p3.CreateTexture("Image/number_middle_3.png",ren);
        if(Count%10==4) p3.CreateTexture("Image/number_middle_4.png",ren);
        if(Count%10==5) p3.CreateTexture("Image/number_middle_5.png",ren);
        if(Count%10==6) p3.CreateTexture("Image/number_middle_6.png",ren);
        if(Count%10==7) p3.CreateTexture("Image/number_middle_7.png",ren);
        if(Count%10==8) p3.CreateTexture("Image/number_middle_8.png",ren);
        if(Count%10==9) p3.CreateTexture("Image/number_middle_9.png",ren);
        p3.Render(ren);
        Count/=10;
        length--;
    }while(Count!=0);
}



