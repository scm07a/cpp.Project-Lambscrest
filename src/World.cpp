#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "World.h"
#include "Player.h"

World::World(){
    tile.x=0;
    tile.y=0;
    tile.w = _TILEWIDTH;
    tile.h = _TILEHEIGHT;
    wall.x=100;
    wall.y=100;
    wall.w=250;
    wall.h=100;
}

void World::render(SDL_Renderer* renderer,
                    SDL_Texture* texture)
{
    for (size_t row=0;row<22;row++){
        for (size_t col=0;col<39;col++){
            tile.x=col*_TILEWIDTH;
            tile.y=row*_TILEHEIGHT;
            SDL_RenderCopy(renderer,texture,
                            nullptr,&tile);
        }
    }
}

bool World::checkCollison(const SDL_Rect& rect) const{
    return SDL_HasIntersection(&wall,&rect);
}