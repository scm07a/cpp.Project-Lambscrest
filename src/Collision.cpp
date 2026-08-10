#include "Collision.h"
#include <SDL2/SDL.h>

SDL_Rect Collision::spriteCollBox(const SDL_Rect& spriteRect,
                                const CollisionBox& collBox) const
{
    return SDL_Rect{spriteRect.x+collBox.offsetX,
                    spriteRect.y+collBox.offsetY,
                    collBox.width,
                    collBox.height
                    };
}
Collision::Collision()=default;

void Collision::debugDrawCollBox(SDL_Renderer* renderer,
                            const SDL_Rect& spriteRect)const
{
    //* Draws a box of the Rect Collision 
    SDL_RenderDrawRect(renderer,&spriteRect);
}