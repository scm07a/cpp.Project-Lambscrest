#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include "Game.h"
#include "TextureManager.h"

Game::Game():window(nullptr),
            renderer(nullptr),
            isRunning(true)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        throw std::runtime_error(
            std::string("SDL App Initialization Error:") 
            + SDL_GetError());
    }

    window=SDL_CreateWindow("Project Lambscrest",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            1280,
                            720,
                            SDL_WINDOW_RESIZABLE);


    if(!window){
        throw std::runtime_error(
            std::string("SDL Window Creation Error:") 
            + SDL_GetError());
    }


    renderer=SDL_CreateRenderer(
                        window,
                        -1,
                        SDL_RENDERER_ACCELERATED);

    if(!renderer){
        throw std::runtime_error(
            std::string("SDL Renderer Creation Error:") 
            + SDL_GetError());
    }
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
double Game::calcSpeed(Uint64& lastTick){
    Uint64 currentTick = SDL_GetPerformanceCounter();
    double _deltaTime = static_cast<double>
                        (currentTick-lastTick)/
                        static_cast<double>(
                        SDL_GetPerformanceFrequency());
    lastTick=currentTick;
    return _deltaTime;
}

bool Game::eventhandler(){
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if(event.type==SDL_QUIT) return false;
    return true;
}   

void Game::processInput(double dt){
    const Uint8* keyboardState = 
        SDL_GetKeyboardState(nullptr);
    player.handleInput(keyboardState);
    // handleCollision();
    player.update(dt,world);
}

void Game::render(TextureManager& tm){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    world.render(renderer,tm.getTexture("background"));
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderDrawRect(renderer,&world.getWall());
    SDL_RenderFillRect(renderer,&world.getWall());
    player.render(renderer,tm.getTexture("player"));
    SDL_RenderPresent(renderer);
}

bool Game::run(){
    tm.loadTexture(renderer,"player","assets/textures/characters/player.png");
    tm.loadTexture(renderer,"background","assets/textures/tilesets/grass.png");
    Uint64 lastTick = SDL_GetPerformanceCounter();

    while(isRunning){
        double _deltaTime= calcSpeed(lastTick);
        if(!eventhandler()) isRunning=false;
        processInput(_deltaTime);
        render(tm);
    }
    return true;
}

// void Game::handleCollision(){
//     if (world.checkCollison(player.getdstRect())){
        
//     }
// }