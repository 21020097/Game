#include"Control.h"
#include <SDL_mixer.h>
Mix_Chunk* gMusic ;
int main(int argc,char** argv)
{
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        //success = false;
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    //success = false;
    }


    Control* game = new Control();
    gMusic = Mix_LoadWAV( "Mix/beat.wav" );
    Mix_PlayChannel( -1, gMusic, -1 );
    game -> Init();
    game -> MainMenu();
    game->GenBlock();
    long long time = 0;
    double first,last=0;
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

    game->Clear();

    return 0 ;
}

