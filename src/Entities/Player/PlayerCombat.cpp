#include "Player.h"

void Player::handleAtk(SDL_Event& event){
    if (event.type!=SDL_MOUSEBUTTONDOWN) return; 
    if(event.button.button!=SDL_BUTTON_LEFT) return;
    switch (dir){
        case Direction::North:
            state=PlayerState::AttackNorth;
            break;
        case Direction::South:
            state=PlayerState::AttackSouth;
            break;
        case Direction::East:
            state=PlayerState::AttackEast;
            break;
        case Direction::West:
            state=PlayerState::AttackWest;
            break;
        default:
            break;
    }
    currentframe=0;
    animtimer=0.f;
}

bool Player::isAtk()const{
    return state==PlayerState::AttackEast||
            state==PlayerState::AttackNorth||
            state==PlayerState::AttackSouth||
            state==PlayerState::AttackWest;
}