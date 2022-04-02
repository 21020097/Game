#include"Control.h"
void INIT()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}
Control* game = new Control();
int main(int argc,char** argv)
{
    INIT();


    game -> Init();
    long long time = 0;
    double first,last=0;
    game -> Gen();
    while(!game->getExit())
    {
        game->Event();
        game->Render();


        first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
		}
		last = first;
    }
    game->Clear();
    return 0 ;
}

