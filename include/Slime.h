#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "Collision.h"
#include "Direction.h"

constexpr int GRIDSIZE = 32;
constexpr int slimeWidth=150;
constexpr int slimeHeight=90;

namespace EnemyAnimation{
constexpr int atkframes=3;
constexpr int idleframes=4;
constexpr int deathframes=5;
constexpr int idleNorthIndex=2;
constexpr int idleSouthIndex=0;
constexpr int idleSidesIndex=1;
constexpr int deathindex=12;
constexpr int attackNorthIndex=11;
constexpr int attackSouthIndex=9;
constexpr int attackSidesIndex=10;
};

enum class EnemyState{
    IdleNorth,
    IdleSouth,
    IdleWest,
    IdleEast,
    AttackSouth,
    AttackEast,
    AttackWest,
    AttackNorth,
    DeathEast,
    DeathWest
};

constexpr CollisionBox EnemyCollision{
    55,9,150,90
};

class Slime{
    private:
        int health;
        bool isAlive;
        SDL_Rect dstrect;
        SDL_Rect srcrect;
        Direction dir;
        EnemyState state;
    public:
        Slime();
        void render(SDL_Renderer* renderer,TextureManager& tm);
        bool getHitBox();
};