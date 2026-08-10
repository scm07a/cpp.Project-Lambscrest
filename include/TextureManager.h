#pragma once
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>

class TextureManager{
    private:
        std::unordered_map<std::string,SDL_Texture*> textures;
    public:
        TextureManager();
        ~TextureManager();
        bool loadTexture(SDL_Renderer* renderer,
                        const std::string& key,
                        const std::string& path);
        SDL_Texture* getTexture(const std::string& key);
        void clear();
};