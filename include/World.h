#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"

class World{
    private:
        SDL_Rect wall;

    public:
        World();
        void render(SDL_Renderer* renderer, SDL_Texture* texture);
};