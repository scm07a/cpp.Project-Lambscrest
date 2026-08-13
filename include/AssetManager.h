#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include "TextureManager.h"
using json = nlohmann::json;

class AssetManager{
    private:
        json data;
        std::string basePath;
        TextureManager& tm;
    public:
        AssetManager(TextureManager& textureManager);
        bool loadAssets(SDL_Renderer* renderer,
                        const std::string& path);
        std::string get_tpath(const std::string& key)const;
};