#include "Slime.h"

void Slime::render(SDL_Renderer* renderer, TextureManager& tm){
    SDL_RendererFlip flip=SDL_FLIP_NONE;
    SDL_Texture* textureKey=tm.getTexture("slime");
    if(dir==Direction::West) flip=SDL_FLIP_HORIZONTAL;
    SDL_RenderCopyEx(renderer,textureKey,&srcrect,
                    &dstrect,0.f,nullptr,flip);
}