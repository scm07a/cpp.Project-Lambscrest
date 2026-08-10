#pragma once
#include <nlohmann/json.hpp>
#include <string>
using json = nlohmann::json;

class AssetManager{
    private:
        json data;
        std::string basePath;
    public:
        AssetManager();
        bool loadAssets(const std::string& path);
        std::string get_tpath(const std::string& key)const;
};