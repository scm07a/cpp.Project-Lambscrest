#pragma once
#include <SDL2/SDL.h>
#include "World.h"
#include "Player.h"
#include "TextureManager.h"
#include "Collision.h"
#include "AssetManager.h"

class Game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
        Player player;
        World world;
        TextureManager tm;
        Collision coll;
        AssetManager am;
    public:
        Game();
        ~Game();
        double calcSpeed(Uint64& lastTick);
        bool eventhandler();
        void processInput(double dt);
        void render();
        bool run();
        void handleCollision();
};