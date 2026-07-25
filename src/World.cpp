#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "World.h"

World::World():pos_x(100.f),pos_y(100){
    wall.x=static_cast<int>(pos_x);
    wall.y=static_cast<int>(pos_y);
    wall.w = _TILEWIDTH;
    wall.h = _TILEHEIGHT;
}

void World::render(SDL_Renderer* renderer,
                    SDL_Texture* texture)
{
    for (size_t i=0;i<15;i++){
        for (size_t j=0; j<26;j++){
            SDL_RenderCopy(renderer,texture,
                            nullptr,&wall);
        }
    }
}