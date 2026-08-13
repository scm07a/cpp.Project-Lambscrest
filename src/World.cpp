#include <SDL2/SDL.h>
#include "World.h"
#include "Collision.h"
#include "shrdconst.h"
#include "TextureManager.h"

World::World(){
    tile.x=0;
    tile.y=0;
    tile.w = _TILEWIDTH;
    tile.h = _TILEHEIGHT;
    lBorder={0,0,1,__ScreenHeight};
    rBorder={__ScreenWidth-1,0,1,__ScreenHeight};
    upBorder={0,0,__ScreenWidth,1};
    downBorder={0,__ScreenHeight-1,__ScreenWidth,1};
}

//* Load World Tiles
void World::render(SDL_Renderer* renderer,
                    TextureManager& tm)
{
    SDL_Texture* grassKey= tm.getTexture("grass");
    for (size_t row=0;row<22;row++){
        for (size_t col=0;col<39;col++){
            tile.x=col*_TILEWIDTH;
            tile.y=row*_TILEHEIGHT;
            SDL_RenderCopy(renderer,grassKey,
                            nullptr,&tile);
        }
    }
}

bool World::checkCollison(const SDL_Rect& rect) const{
    return SDL_HasIntersection(&lBorder,&rect)||
            SDL_HasIntersection(&rBorder,&rect)||
            SDL_HasIntersection(&upBorder,&rect)||
            SDL_HasIntersection(&downBorder,&rect);
}