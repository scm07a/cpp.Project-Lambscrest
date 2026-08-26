#include "Slime.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>

Slime::Slime():health(100),isAlive(true),dir(Direction::South){
    srcrect.w=GRIDSIZE;
    srcrect.h=GRIDSIZE;
    srcrect.x=0;
    srcrect.y=0;
    dstrect.w=slimeWidth;
    dstrect.h=slimeHeight;
    dstrect.x=100;
    dstrect.y=100;
}

void Slime::render(SDL_Renderer* renderer, TextureManager& tm){
    SDL_RendererFlip flip=SDL_FLIP_NONE;
    SDL_Texture* textureKey=tm.getTexture("slime");
    if(dir==Direction::West) flip=SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer,textureKey,&srcrect,
                    &dstrect,0.f,nullptr,flip);
}