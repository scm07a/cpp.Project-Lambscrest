#include "World.h"

bool World::checkCollison(const SDL_Rect& rect) const{
    return SDL_HasIntersection(&lBorder,&rect)||
            SDL_HasIntersection(&rBorder,&rect)||
            SDL_HasIntersection(&upBorder,&rect)||
            SDL_HasIntersection(&downBorder,&rect);
}