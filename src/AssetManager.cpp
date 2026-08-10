#include "AssetManager.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

AssetManager::AssetManager(){
    char* path = SDL_GetBasePath();
    if(!path)
        throw std::runtime_error("Failed To Find .exe Path");
    
    basePath=path;
    SDL_free(path);
}

bool AssetManager::loadAssets(const std::string& path){
    std::ifstream file(basePath+ "../"+path);
    if (!file.is_open()) return false;
    try{
            file>>data;
    }
    catch(const json::parse_error&e){
        std::cerr<<e.what()<<std::endl;
        return false;
    }
    return true;
}

std::string AssetManager::get_tpath(const std::string& key)const{
    return basePath + "../" + data["textures"][key].get<std::string>();
}