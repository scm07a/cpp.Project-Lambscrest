#include "AssetManager.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

AssetManager::AssetManager(TextureManager& textureManager):
                        tm(textureManager){
    char* path = SDL_GetBasePath();
    if(!path)
        throw std::runtime_error("Failed To Find .exe Path");
    
    basePath=path;
    SDL_free(path);
}

bool AssetManager::loadAssets(SDL_Renderer* renderer,
                            const std::string& path){
    std::ifstream file(basePath+ "../"+path);
    if (!file.is_open()) return false;
    try{
            file>>data;
    }
    catch(const json::parse_error&e){
        std::cerr<<e.what()<<std::endl;
        return false;
    }
    for (const auto& [key,texturePath]: data["textures"].items()){
        std::string fullPath = basePath + "../" + 
                            texturePath.get<std::string>();
        std::cout << "KEY:  " << key << '\n';
        std::cout << "PATH: " << texturePath << '\n';
        if(!tm.loadTexture(renderer,key,fullPath)){
            std::cerr << "Failed to load texture: "
                        << key << std::endl;
        }
    }
    return true;
}

std::string AssetManager::get_tpath(const std::string& key)const{
    return basePath + "../" + data["textures"][key].get<std::string>();
}