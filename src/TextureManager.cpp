#include "TextureManager.h"
#include <iostream>
#include <stdexcept>

TextureManager::TextureManager()=default;

bool TextureManager::loadTexture(SDL_Renderer* renderer,
                                const std::string& key,
                                const std::string& path)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(!surface){
        std::cerr<<IMG_GetError()<<'\n';
        return false;
    }
    SDL_Texture* texture =
            SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture){
        std::cerr<<"Unable To Convert To Texture" <<'\n'
                    <<IMG_GetError()<< '\n';
        SDL_FreeSurface(surface);
        return false;
    }
    SDL_FreeSurface(surface);
    textures[key] = texture;
    return true;
}

SDL_Texture* TextureManager::getTexture(const std::string& key){
    auto it = textures.find(key);
    if(it == textures.end()){
        throw std::runtime_error(
            std::string("Texture["+ key +"] was not found"));
    }
    return it->second;
}

TextureManager::~TextureManager(){
    for (const auto& it: textures)
        SDL_DestroyTexture(it.second);
}

void TextureManager::clear(){
    for (auto& [key,texture]: textures)
        SDL_DestroyTexture(texture);
    textures.clear();
}