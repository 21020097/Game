#include"Control.h"

// Khỏi tạo con trỏ game
Control* game = new Control();

int main(int argc,char** argv)
{
    game -> Init();
    game -> MainMenu();
    double first;
	double last = 0;
    while(game->getContinue())
    {
        game->Event();

//        game->Update();

        game->Render();

        // Tính toán cho game mượt hơn
        first = SDL_GetTicks();
		if (first - last < 15)
		{
			SDL_Delay(15 - (first - last));
		}
		last = first;
    }

    game->Clear();
    return 0 ;
}

