#pragma once
#include <SDL2/SDL.h>
#include "World.h"
#include "Player.h"
#include "TextureManager.h"

class Game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
        Player player;
        World world;
        TextureManager tm;
    public:
        Game();
        ~Game();
        double calcSpeed(Uint64& lastTick);
        bool eventhandler();
        void processInput(double dt);
        void render(TextureManager& tm);
        bool run();
        void handleCollision();
};