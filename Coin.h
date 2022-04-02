#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include"Object.h"
#include"TextureManager.h"
class Coin : public Object
{
private:
    SDL_Texture* Tex;
    Object coin;
    int timer;
    int animationTimer;
public:
    Coin();
	void Render(SDL_Renderer* ren);
};
