#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include "Object.h"
class Score
{
private:
    Object p,p2,p3;
public:
    void Render(SDL_Renderer* ren,int Count);

    void Render_Score(SDL_Renderer* ren,int Count);

    void Render_Best(SDL_Renderer* ren,int Count);
};
