#include"MainMenu.h"


MainMenu::MainMenu()
{
    isClicked = false ;
//    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
//    gClick = Mix_LoadWAV("Clicked.wav");
}

void MainMenu::Init(SDL_Renderer* ren)
{
    menuBackGround = TextureManager::Texture("Image/MainMenu.png",ren);

}

// Xử lý sự kiện
int MainMenu::EventHandling(SDL_Event& e)
{
    SDL_PollEvent(&e);

    if(e.type==SDL_QUIT) return -1;
    else
    {
        // Tọa độ của con trỏ chuột nằm bên trong chữ play
        if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 470 && e.motion.y < 535)
        {
            isClicked = true;
            //Mix_FreeChunk(gClick);
        }
    }
	return 0;
}

void MainMenu::Render(SDL_Renderer* ren)
{
    // Vẽ cái Menu ra
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

