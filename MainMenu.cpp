#include"MainMenu.h"


MainMenu::MainMenu()
{
    isClicked = false ;
//    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
//    gClick = Mix_LoadWAV("Clicked.wav");
    //glass.setSrc(0,0,1,1);
    //glass.setDest(260,470,,100);
}

void MainMenu::Init(SDL_Renderer* ren)
{
    menuBackGround = TextureManager::Texture("Image/MainMenu.png",ren);
    //glass.CreateTexture("Image/glass.png",ren);
}

// Xử lý sự kiện
int MainMenu::EventHandling(SDL_Event& e,SDL_Renderer* ren)
{
    SDL_PollEvent(&e);

    if(e.type==SDL_QUIT) return -1;
    else
    {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 470 && e.motion.y < 535)
        {
            isClicked = true;
        }
    }


	return 0;
}

void MainMenu::Render(SDL_Renderer* ren)
{
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,menuBackGround,NULL,NULL);
        SDL_RenderPresent(ren);
}

bool MainMenu::getClicked()
{
    return isClicked;
}

MainMenu:: ~MainMenu()
{
    isClicked = false ;
}

