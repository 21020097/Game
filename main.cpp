#include"Control.h"

// Khỏi tạo con trỏ game
Control* game = new Control();

int main(int argc,char** argv)
{
    game -> Init();
    game -> MainMenu();
    game->Clear();
    return 0 ;
}

