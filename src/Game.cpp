#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "TextureManager.h"
#include "Collision.h"
#include "shrdconst.h"

Game::Game():window(nullptr),
            renderer(nullptr),
            isRunning(true),
            am(tm)
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        throw std::runtime_error(
            std::string("SDL App Initialization Error:") 
            + SDL_GetError());
    }

    int imgFlags = IMG_INIT_PNG;

    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags)
    {
        throw std::runtime_error(
            std::string("SDL Image Initialization Error: ")
            + IMG_GetError());
    }

    if(TTF_Init()!=0){
        throw std::runtime_error(
            std::string("SDL TTF Initialization Error:")
            +TTF_GetError());
    }

    window=SDL_CreateWindow("Project Lambscrest",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            __ScreenWidth,
                            __ScreenHeight,
                            SDL_WINDOW_FULLSCREEN);


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
    SDL_RenderSetLogicalSize(renderer,
                            __ScreenWidth,
                            __ScreenHeight);
}

Game::~Game(){
    tm.clear();
    IMG_Quit();
    TTF_Quit();
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

void Game::render(){
    // SDL_Rect debugPlayerCollision =
    //             coll.spriteCollBox(player.getdstRect(),
    //                             playerCollision);
    SDL_RenderClear(renderer);
    world.render(renderer,tm.getTexture("grass"));
    // SDL_RenderDrawRect(renderer,&world.getWall());

    // Collision Box Visualization
    // Player
    // coll.debugDrawCollBox(renderer,debugPlayerCollision);

    // White Rectangle
    // SDL_SetRenderDrawColor(renderer,255,255,255,255);
    // SDL_RenderFillRect(renderer,&world.getWall());

    player.render(renderer,tm.getTexture("player"));
    SDL_RenderPresent(renderer);
}

bool Game::run(){
    if(!am.loadAssets(renderer,"assets/assets.json"))
        throw std::runtime_error("Failed To Load assets.json file");
    // tm.loadTexture(renderer,"player",
    //             am.get_tpath("player"));

    // tm.loadTexture(renderer,"grass",
    //                 am.get_tpath("grass"));

    Uint64 lastTick = SDL_GetPerformanceCounter();

    while(isRunning){
        double _deltaTime= calcSpeed(lastTick);
        if(!eventhandler()) isRunning=false;
        processInput(_deltaTime);
        render();
    }
    return true;
}
