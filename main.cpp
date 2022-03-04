#include"Control.h"

// Khỏi tạo con trỏ game
Control* game = new Control();

int main(int argc,char** argv)
{
    game -> Init();

    while(game->getisMenu()&&game->getContinue())
    {
        game->Event();
        game->Render_Menu();
    }

    while(game->getContinue())
    {
        game->Event();
        game-> Render_Background();
    }

    game->Clear();
    return 0 ;
}

