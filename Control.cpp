#include"Control.h"
#include<iostream>
Control::Control()
{
    window = NULL;
    renderer = NULL;

    Continue = true;
    isMenu = true;

    srcPlayer.h = 60 ;
    srcPlayer.w = 80 ;
    srcPlayer.x = srcPlayer.y = 0 ;

    destPlayer.h = 60;
    destPlayer.w = 80;
    destPlayer.x = 20 ;
    destPlayer.y = 20 ;
};


void Control::Init()
{
    // Khởi tạo SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Tạo một cửa sổ Window có tên là Game
    //                        Tên       Căn chính giữa       Căn chính giữa          Chiều dài/rộng     khởi tạo
    // Con trỏ window được gán thành màn hình khởi tạo
    window  = SDL_CreateWindow("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);

    // vẽ con trỏ renderer lên màn window
    renderer=SDL_CreateRenderer(window,-1,0);

    Background = GenTexture::Texture("Image/background.png",renderer);
    Menu = GenTexture::Texture("Image/message.png",renderer);

    Bird1 = GenTexture::Texture("Image/yellowbird1.png",renderer);
    Bird2 = GenTexture::Texture("Image/yellowbird2.png",renderer);
    Bird3 = GenTexture::Texture("Image/yellowbird3.png",renderer);
}

void Control::Render_Menu()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,Menu,NULL,NULL);
    SDL_RenderPresent(renderer);
}

void Control::Render_Background()
{
    // Xóa đi reset lại renderer cũ
    SDL_RenderClear(renderer);
    // Vẽ ảnh ra biến player được copy vào biến render và kéo ra vô định NULL NULL
    SDL_RenderCopy(renderer,Background,NULL,NULL);

    // Vẽ con chim

    SDL_RenderCopy(renderer,Bird1,&srcPlayer,&destPlayer);
    SDL_Delay(10);
    //SDL_RenderCopy(renderer,Bird2,&srcPlayer,&destPlayer);
        SDL_Delay(10);

    //SDL_RenderCopy(renderer,Bird3,&srcPlayer,&destPlayer);
        SDL_Delay(10);


    // Mang hết tất cả thông tin của renderer vẽ ra màn hình
    SDL_RenderPresent(renderer);
}

void Control::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Control::Event()
{

    SDL_PollEvent(&event);
    // Nếu ấn nút thoát
    if(event.type == SDL_QUIT)
    {
        Continue = false;
    }


    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        isMenu = false ;
    }
    // Nếu ấn bàn phím xuống
    if(event.type == SDL_KEYDOWN)
    {
        // Nếu ấn phím w
        if(event.key.keysym.sym==SDLK_w)
        {
            std::cout<<"Success";
            destPlayer.y-=15;
        }

        if(event.key.keysym.sym==SDLK_q)
        {
            Continue = false;
        }
    }
}

void Control::Update()
{
    destPlayer.y+=3;SDL_Delay(10);
}


bool Control::getContinue()
{
    return Continue;
}

bool Control::getisMenu()
{
    return isMenu;
}
