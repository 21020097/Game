#include "Coin.h"

Coin::Coin()
{
	animationTimer = 0;
	timer = 10;
	coin.setDest(10,10,40,40);
}

void Coin::Render(SDL_Renderer* ren)
{
    animationTimer++;
	if (animationTimer < timer)
	{
		coin.setSrc(0, 0, 80, 80);
	}
	else if (animationTimer >= timer && animationTimer <= timer * 2)
	{
		coin.setSrc(0, 80, 80, 80);
	}
	else if (animationTimer >= timer * 2 && animationTimer <= timer * 3)
	{
		coin.setSrc(0, 160, 80, 80);
	}
	else if (animationTimer >= timer * 3 && animationTimer <= timer * 4)
	{
		coin.setSrc(0, 240, 80, 80);
	}
	else if (animationTimer >= timer * 4 && animationTimer <= timer * 5)
	{
		coin.setSrc(0, 320, 80, 80);
	}
	else if (animationTimer >= timer * 5 && animationTimer <= timer * 6)
	{
		coin.setSrc(0, 400, 80, 80);
	}
	else if (animationTimer >= timer * 6 && animationTimer <= timer * 7)
	{
		coin.setSrc(0, 480, 80, 80);
	}
	else if (animationTimer >= timer * 7 && animationTimer <= timer * 8)
	{
		coin.setSrc(0, 560, 80, 80);
	}
	else if (animationTimer >= timer * 8 && animationTimer <= timer * 9)
	{
		coin.setSrc(0, 640, 80, 80);
	}
	else if (animationTimer >= timer * 9 && animationTimer <= timer * 10)
	{
		coin.setSrc(0, 720, 80, 80);
	}
	if (animationTimer > timer * 11)
	{
		animationTimer = 0;
	}
	SDL_Rect Src = coin.getSrc();
	SDL_Rect Dest = coin.getDest();
	SDL_RenderCopy(ren, getTexture(), &Src, &Dest);

}
