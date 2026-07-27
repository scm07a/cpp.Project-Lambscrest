#pragma once
#include <SDL2/SDL.h>

constexpr int _FRAMESIZE = 48;
constexpr double _FRAMETIME = 0.2;

enum class PlayerState{
    IdleNorth,
    IdleSouth,
    WalkNorth,
    WalkSouth,
    WalkEast,
    WalkWest,
    IdleWest,
    IdleEast
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
    public:
        Player();
        void handleInput(const Uint8* keyboardState);
        void update(double dt);
        void render(SDL_Renderer* renderer,
                    SDL_Texture* texture);
        const SDL_Rect& getdstRect() const;
};