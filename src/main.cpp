#define SDL_MAIN_HANDLED
#include <iostream>
#include <stdexcept>
#include "Game.h"

int main(){
    try{
        Game game;
        return game.run() ? 0:1;
    }
    //*Catch All Errors in *.cpp
    catch(const std::exception& e){
        std::cerr<<e.what()<<std::endl;
        return 2;
    }
}