#pragma once
#include <SDL2/SDL.h>
#include "World.h"
#include "Player.h"
#include "Slime.h"
#include "Asset Headers/TextureManager.h"
#include "Collision.h"
#include "Asset Headers/AssetManager.h"

class Game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
        Player player;
        Slime slime;
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