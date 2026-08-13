#pragma once
#include <SDL2/SDL.h>

struct CollisionBox{
    int offsetX;
    int offsetY;
    int width;
    int height;
};



class Collision{
    public:
        SDL_Rect spriteCollBox(const SDL_Rect& spriteRect,
                                const CollisionBox& collBox) const;
        void debugDrawCollBox(SDL_Renderer* renderer,
                            const SDL_Rect& rect)const;
        Collision();
};