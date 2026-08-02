#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"

constexpr int _TILEWIDTH=50;
constexpr int _TILEHEIGHT=50;

class World{
    private:
        SDL_Rect tile;
        SDL_Rect wall;

    public:
        World();
        void render(SDL_Renderer* renderer, SDL_Texture* texture);
        bool checkCollison(const SDL_Rect& rect) const;
        const SDL_Rect& getWall() const;
};