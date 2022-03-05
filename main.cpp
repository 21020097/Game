#include"Control.h"

// Khỏi tạo con trỏ game
Control* game = new Control();

int main(int argc,char** argv)
{

    game -> Init();
//start:
    game -> MainMenu();

    game->GenBlock();
double first,last=0;
    long long time = 0;
    while(game->getContinue())
    {
        time++;
        game->Event();

        game->Render();

        first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
		}
		last = first;
    }

//goto start;
    game->Clear();
    return 0 ;
}

