#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"



class World{
    private:
        SDL_Rect tile;
        // SDL_Rect wall;
        SDL_Rect lBorder;
        SDL_Rect rBorder;
        SDL_Rect upBorder;
        SDL_Rect downBorder;

    public:
        World();
        void render(SDL_Renderer* renderer, SDL_Texture* texture);
        bool checkCollison(const SDL_Rect& rect) const;
        // const SDL_Rect& getWall() const;
};