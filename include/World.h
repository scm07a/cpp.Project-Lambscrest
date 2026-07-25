#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"

constexpr int _TILEWIDTH=48;
constexpr int _TILEHEIGHT=48;
class World{
    private:
        SDL_Rect wall;
        int pos_x;
        float pos_y;

    public:
        World();
        void render(SDL_Renderer* renderer, SDL_Texture* texture);
};