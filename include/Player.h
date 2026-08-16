#pragma once
#include <SDL2/SDL.h>
#include "World.h"
#include "Collision.h"
#include "TextureManager.h"

//* Player Frame Indices and Sizes
constexpr int _FRAMESIZE = 48;
constexpr double _FRAMETIME = 0.2;
constexpr int playerWidth=150;
constexpr int playerHeight=90;
constexpr int idleSouthIndex=0;
constexpr int idleSidesIndex=1;
constexpr int idleNorthIndex=2;
constexpr int walkSouthIndex=3;
constexpr int walkSidesIndex=4;
constexpr int walkNorthIndex=5;
constexpr int attackSouthIndex=6;
constexpr int attackSidesIndex=7;
constexpr int attackNorthIndex=8;
constexpr int deathIndex=9;
constexpr int walkFrames = 6;
constexpr int attackFrames = 4;
constexpr int deathFrames=3;

enum class PlayerState{
    IdleNorth,
    IdleSouth,
    WalkNorth,
    WalkSouth,
    WalkEast,
    WalkWest,
    IdleWest,
    IdleEast,
    AttackSouth,
    AttackEast,
    AttackWest,
    AttackNorth,
    DeathEast,
    DeathWest
};

enum class Direction{
    North,
    South,
    West,
    East
};

struct Animation{
    int rows,frames;
};

constexpr CollisionBox playerCollision{
    55,
    42,
    41,
    35
};

class Player{
    private:
        Direction dir= Direction::South;
        PlayerState state = PlayerState::IdleNorth;
        Animation anim;
        float moveX = 0.f;
        float moveY = 0.f;
        float speed = 150.f;
        float x;
        float y;
        // int health = 100;
        // bool isAlive = true;
        SDL_Rect dstrect;
        SDL_Rect srcrect;
        int currentframe;
        double animtimer;
        Collision coll;
    public:
        Player();
        void handleInput(const Uint8* keyboardState,
                        const Uint8* mouseState);
        void update(double dt,World& world);
        void render(SDL_Renderer* renderer,
                    TextureManager& tm);
        const SDL_Rect& getdstRect() const;
        int getdstRect_X() const;
        int getdstRect_Y() const;
};