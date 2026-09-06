#include "Player.h"

void Player::keyboardInput(const Uint8* keyboardState){
    if (isAtk()) return;
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

