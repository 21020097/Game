/*
#include"MainMenu.h"
#include"Control.h"
MainMenu::MainMenu()
{
    isClicked = false ;
    rectstart.setDest(350,300,50,100);
    rectstart.setSrc(0,0,50,100);

    //Bird.setDest
}

void MainMenu::Init(SDL_Renderer* ren)
{
    menuBackGround = TextureManager::Texture("Image/background.png",ren);
    start   = TextureManager::Texture("Image/button_play_normal.png",ren);
    started = TextureManager::Texture("Image/button_play_pressed.png",ren);


}

int MainMenu::EventHandling(SDL_Event& e,SDL_Renderer* ren)
{
    SDL_PollEvent(&e);

    if(e.type==SDL_QUIT) return -1;
    else
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            isClicked = true;
        }
    }


	return 0;
}

void MainMenu::Render(SDL_Renderer* ren)
{
    SDL_Rect pDest = rectstart.getDest();
    SDL_Rect pSrc = rectstart.getSrc();

    if(!isClicked)
    {
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,menuBackGround,NULL,NULL);
//        Bird.Render(renderer);
        SDL_RenderCopy(ren,start,&pSrc,&pDest);
        SDL_RenderPresent(ren);
    }
    else
    {
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,menuBackGround,NULL,NULL);
//        Bird.Render(renderer);
        SDL_RenderCopy(ren,started,&pSrc,&pDest);
        SDL_RenderPresent(ren);
    }
}

bool MainMenu::getClicked()
{
    return isClicked;
}

MainMenu:: ~MainMenu()
{
    isClicked = false ;
}
*/
