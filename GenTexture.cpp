#include"GenTexture.h"

// Vẽ ảnh
SDL_Texture* GenTexture::Texture(const char* path,SDL_Renderer* ren)
{
    SDL_Surface* surface;
    surface = IMG_Load(path);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(ren,surface);
    return tex;
}
