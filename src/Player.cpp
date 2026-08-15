#include "Player.h"
#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>
#include "Constants.h"
#include "TextureManager.h"

Player::Player(): x(100.f),y(100.f),
                currentframe(0),animtimer(0.0)
{
    anim.rows=0;
    anim.frames=6;
    dstrect.w=playerWidth;
    dstrect.h=playerHeight;
    dstrect.x=static_cast<int>(x);
    dstrect.y=static_cast<int>(y);
    srcrect.w=_FRAMESIZE;
    srcrect.h=_FRAMESIZE;
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
    SDL_Rect nextSpriteRect=dstrect;
    nextSpriteRect.x=static_cast<int>(nextX);
    nextSpriteRect.y=static_cast<int>(nextY);
    SDL_Rect nextRect=coll.spriteCollBox(nextSpriteRect,playerCollision);
    if(!world.checkCollison(nextRect)){
        x=nextX;
        y=nextY;

        dstrect.x=static_cast<int>(x);
        dstrect.y=static_cast<int>(y);
    }
    animtimer+=dt;
    if(animtimer>_FRAMETIME){
        anim.frames=walkFrames;
        switch(state){
            case PlayerState::IdleNorth:
                anim.rows=idleNorthIndex;
                break;

            case PlayerState::WalkNorth:
                anim.rows=walkNorthIndex;
                break;

            case PlayerState::IdleEast:
                anim.rows=idleSidesIndex;
                break;

            case PlayerState::WalkEast:
                anim.rows=walkSidesIndex;
                break;
            
            case PlayerState::IdleWest:
                anim.rows=idleSidesIndex;
                break;
            
            case PlayerState::WalkWest:
                anim.rows=walkSidesIndex;
                break;
            
            case PlayerState::IdleSouth:
                anim.rows=idleSouthIndex;
                break;

            case PlayerState::WalkSouth:
                anim.rows=walkSouthIndex;
                break;

            case PlayerState::AttackSouth:
                anim.frames=attackFrames;
                anim.rows=attackSouthIndex;
                break;
            
            case PlayerState::AttackEast:
                anim.frames=attackFrames;
                anim.rows=attackSidesIndex;
                break;
            
            case PlayerState::AttackWest:
                anim.frames=attackFrames;
                anim.rows=attackSidesIndex;
                break;

            case PlayerState::AttackNorth:
                anim.frames=attackFrames;
                anim.rows=attackNorthIndex;
                break;
            
            case PlayerState::DeathEast:
                anim.frames=deathFrames;
                anim.rows=deathIndex;
                break;
            
            case PlayerState::DeathWest:
                anim.frames=deathFrames;
                anim.rows=deathIndex;
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
                    TextureManager& tm){
    
    SDL_Texture* textureKey= tm.getTexture("player");
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (dir==Direction::West)
        flip=SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer,textureKey,&srcrect,&dstrect
                    ,0.0,nullptr,flip);
}
const SDL_Rect& Player::getdstRect() const{
    return dstrect;
}

int Player::getdstRect_X()const{
    return dstrect.x;
}

int Player::getdstRect_Y()const{
    return dstrect.y;
}