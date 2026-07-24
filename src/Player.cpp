    #include "Player.h"
    #include <SDL2/SDL.h>
    #include <stdexcept>
    #include <iostream>

    Player::Player(): x(100.f),y(100.f),
                    currentframe(0),animtimer(0.0)
    {
        anim.rows=0;
        anim.frames=6;
        dstrect.w=200;
        dstrect.h=150;
        dstrect.x=static_cast<int>(x);
        dstrect.y=static_cast<int>(y);
        srcrect.w=48;
        srcrect.h=48;
        srcrect.x= currentframe * 48;
        srcrect.y= anim.rows * 48;
    }   

    void Player::handleInput(const Uint8* keyboardState){
        moveX=0.f;
        moveY=0.f;
        bool movingfront = false;
        bool movingback = false;
        bool movingleft = false;
        bool movingright = false;

        if(keyboardState[SDL_SCANCODE_W]){
            moveY=-1.f;
            state=PlayerState::WalkNorth;
            dir=Direction::North;
            movingfront=true;
        }

        else if(keyboardState[SDL_SCANCODE_A]){
            moveX=-1.f;
            state=PlayerState::WalkWest;
            dir=Direction::West;
            movingleft=true;
        }

        else if(keyboardState[SDL_SCANCODE_S]){
            moveY=1.f;
            state=PlayerState::WalkSouth;
            dir=Direction::South;
            movingback=true;
        }

        else if(keyboardState[SDL_SCANCODE_D]){
            moveX=1.f;
            state=PlayerState::WalkEast;
            dir=Direction::East;
            movingright=true;
        }

        if (!movingfront && dir==Direction::North)
            state=PlayerState::IdleSouth;

        if (!movingright && dir==::Direction::East)
            state=PlayerState::IdleEast;

        if (!movingback && dir==Direction::South)
            state=PlayerState::IdleNorth;

        if (!movingleft && dir==Direction::West)
            state=PlayerState::IdleWest;
        
    }
    void Player::update(double dt){
        x+=moveX*speed*dt;
        y+=moveY*speed*dt;
        dstrect.x=static_cast<int>(x);
        dstrect.y=static_cast<int>(y);
        animtimer+=dt;
        if(animtimer>0.2){
                switch(state){
                    case PlayerState::IdleNorth:
                        anim.frames=6;
                        anim.rows=0;
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
                        anim.rows=2;
                        break;

                    case PlayerState::WalkSouth:
                        anim.frames=6;
                        anim.rows=3;
                        break;
                    
                    default:
                        std::cout<<"Err!\n";
                        break;
                }
            currentframe=(currentframe+1)%anim.frames;
            srcrect.x=currentframe*48;
            srcrect.y=anim.rows*48;
            animtimer-=0.2;
        }
    }

    void Player::render(SDL_Renderer* renderer,
                        SDL_Texture* texture){
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (dir==Direction::West)
        flip=SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(renderer,texture,&srcrect,&dstrect,0.0,nullptr,flip);
    }