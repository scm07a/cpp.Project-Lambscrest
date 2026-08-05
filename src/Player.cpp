#include "Player.h"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>

Player::Player(): x(100.f),y(100.f),
                currentframe(0),animtimer(0.0)
{
    anim.rows=0;
    anim.frames=6;
    dstrect.w=playerWidth;
    dstrect.h=playerHeight;
    dstrect.x=static_cast<int>(x);
    dstrect.y=static_cast<int>(y);
    srcrect.w=48;
    srcrect.h=48;
    srcrect.x= currentframe * _FRAMESIZE;
    srcrect.y= anim.rows * _FRAMESIZE;
}

void Player::handleInput(const Uint8* keyboardState){
    moveX=0.f;
    moveY=0.f;
    const Uint8 wKey = keyboardState[SDL_SCANCODE_W];
    const Uint8 sKey = keyboardState[SDL_SCANCODE_S];
    const Uint8 aKey = keyboardState[SDL_SCANCODE_A];
    const Uint8 dKey = keyboardState[SDL_SCANCODE_D];
    const Uint8 shiftKey = keyboardState[SDL_SCANCODE_LSHIFT];
    bool moving = false;

    if(wKey){
        moveY=-1.f;
        state=PlayerState::WalkNorth;
        dir=Direction::North;
        moving=true;
    }

    if(sKey){
        moveY=1.f;
        state=PlayerState::WalkSouth;
        dir=Direction::South;
        moving=true;
    }

    if(aKey){
        moveX=-1.f;
        state=PlayerState::WalkWest;
        dir=Direction::West;
        moving=true;
    }


    if(dKey){
        moveX=1.f;
        state=PlayerState::WalkEast;
        dir=Direction::East;
        moving=true;
    }

    if(shiftKey) speed=200.f;
    else if (!shiftKey) speed = 150.f;

    if (!moving && dir==Direction::North)
        state=PlayerState::IdleNorth;

    if (!moving && dir==::Direction::East)
        state=PlayerState::IdleEast;

    if (!moving && dir==Direction::South)
        state=PlayerState::IdleSouth;

    if (!moving && dir==Direction::West)
        state=PlayerState::IdleWest;
    
}
void Player::update(double dt, World& world){
    float nextX=x+moveX*speed*dt;
    float nextY=y+moveY*speed*dt;
    SDL_Rect nextRect=dstrect;
    nextRect.x=static_cast<int>(nextX);
    nextRect.y=static_cast<int>(nextY);
    if(!world.checkCollison(nextRect)){
        x=nextX;
        y=nextY;

        dstrect.x=static_cast<int>(x);
        dstrect.y=static_cast<int>(y);
    }
    animtimer+=dt;
    if(animtimer>_FRAMETIME){
            switch(state){
                case PlayerState::IdleNorth:
                    anim.frames=6;
                    anim.rows=2;
                    break;

                case PlayerState::WalkNorth:
                    anim.frames=6;
                    anim.rows=5;
                    break;

                case PlayerState::IdleEast:
                    anim.frames=6;
                    anim.rows=1;
                    break;

                case PlayerState::WalkEast:
                    anim.frames=6;
                    anim.rows=4;
                    break;
                
                case PlayerState::IdleWest:
                    anim.frames=6;
                    anim.rows=1;
                    break;
                
                case PlayerState::WalkWest:
                    anim.frames=6;
                    anim.rows=4;
                    break;
                
                case PlayerState::IdleSouth:
                    anim.frames=6;
                    anim.rows=0;
                    break;

                case PlayerState::WalkSouth:
                    anim.frames=6;
                    anim.rows=3;
                    break;
                
                default:
                    throw std::runtime_error
                    ("Unknown Player State Inside Player::update()");
                    break;
            }
        currentframe=(currentframe+1)%anim.frames;
        srcrect.x=currentframe*_FRAMESIZE;
        srcrect.y=anim.rows*_FRAMESIZE;
        animtimer-=_FRAMETIME;
    }
}

void Player::render(SDL_Renderer* renderer,
                    SDL_Texture* texture){
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (dir==Direction::West)
        flip=SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer,texture,&srcrect,&dstrect
                    ,0.0,nullptr,flip);
}
const SDL_Rect& Player::getdstRect()const{
    return dstrect;
}
