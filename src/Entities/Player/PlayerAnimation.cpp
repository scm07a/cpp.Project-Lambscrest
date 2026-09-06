#include <stdexcept>
#include "Player.h"

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
    while(animtimer>_FRAMETIME){
        anim.frames=PlayerAnimation::walkFrames;
        switch(state){
            case PlayerState::IdleNorth:
                anim.rows=PlayerAnimation::idleNorthIndex;
                break;

            case PlayerState::WalkNorth:
                anim.rows=PlayerAnimation::walkNorthIndex;
                break;

            case PlayerState::IdleEast:
                anim.rows=PlayerAnimation::idleSidesIndex;
                break;

            case PlayerState::WalkEast:
                anim.rows=PlayerAnimation::walkSidesIndex;
                break;
            
            case PlayerState::IdleWest:
                anim.rows=PlayerAnimation::idleSidesIndex;
                break;
            
            case PlayerState::WalkWest:
                anim.rows=PlayerAnimation::walkSidesIndex;
                break;
            
            case PlayerState::IdleSouth:
                anim.rows=PlayerAnimation::idleSouthIndex;
                break;

            case PlayerState::WalkSouth:
                anim.rows=PlayerAnimation::walkSouthIndex;
                break;

            case PlayerState::AttackSouth:
                anim.frames=PlayerAnimation::attackFrames;
                anim.rows=PlayerAnimation::attackSouthIndex;
                break;
            
            case PlayerState::AttackEast:
                anim.frames=PlayerAnimation::attackFrames;
                anim.rows=PlayerAnimation::attackSidesIndex;
                break;
            
            case PlayerState::AttackWest:
                anim.frames=PlayerAnimation::attackFrames;
                anim.rows=PlayerAnimation::attackSidesIndex;
                break;

            case PlayerState::AttackNorth:
                anim.frames=PlayerAnimation::attackFrames;
                anim.rows=PlayerAnimation::attackNorthIndex;
                break;
            
            case PlayerState::DeathEast:
                anim.frames=PlayerAnimation::deathFrames;
                anim.rows=PlayerAnimation::deathIndex;
                break;
            
            case PlayerState::DeathWest:
                anim.frames=PlayerAnimation::deathFrames;
                anim.rows=PlayerAnimation::deathIndex;
                break;

            default:
                throw std::runtime_error
                ("Unknown Player State Inside Player::update()");
                break;
            }

    if (isAtk()){
        if(currentframe<anim.frames-1) currentframe++;

        else{
            state=PlayerState::IdleSouth;
            currentframe=0;
        }
    }
    else
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