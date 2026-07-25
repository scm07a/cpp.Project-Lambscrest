#define SDL_MAIN_HANDLED
#include <iostream>
#include <stdexcept>
#include "Game.h"

auto main()->int{
    try{
        Game game;
        return game.run() ? 0:1;
    }
    catch(const std::exception& e){
        std::cerr<<e.what()<<std::endl;
        return 2;
    }
}