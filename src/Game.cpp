#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "TextureManager.h"
#include "Collision.h"
#include "Constants.h"

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
                            SDL_WINDOW_FULLSCREEN_DESKTOP);
                            //* Not SDL_WINDOW_FULLSCREEN
                            //* For Console Debugging Purposes


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
    //* Delta Time Calculation For Proper FPS And Game Speed
    //* No Corellation With Animation Speed Only Game Mechanics
    Uint64 currentTick = SDL_GetPerformanceCounter();
    double _deltaTime = static_cast<double>
                        (currentTick-lastTick)/
                        static_cast<double>(
                        SDL_GetPerformanceFrequency());
    lastTick=currentTick;
    return _deltaTime;
    
}

bool Game::eventhandler(){
    //* Handles All Type Off Events (Exiting The Game)
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if(event.type==SDL_QUIT){
            return false;
            player.handleAtk(event);
        }
    return true;
}   

void Game::processInput(double dt){
    const Uint8* keyboardState = 
        SDL_GetKeyboardState(nullptr);
    player.handleInput(keyboardState);
    player.update(dt,world);
}

void Game::render(){
    SDL_RenderClear(renderer);
    world.render(renderer,tm);
    player.render(renderer,tm);
    SDL_RenderPresent(renderer);
}

bool Game::run(){
    if(!am.loadAssets(renderer,"assets/assets.json"))
        throw std::runtime_error("Failed To Load assets.json file");

    Uint64 lastTick = SDL_GetPerformanceCounter();

    while(isRunning){
        double _deltaTime= calcSpeed(lastTick);
        if(!eventhandler()) isRunning=false;
        processInput(_deltaTime);
        render();
    }
    return true;
}