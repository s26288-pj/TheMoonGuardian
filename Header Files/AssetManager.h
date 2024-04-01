#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include "Graphics.h"
#include <map>

class AssetManager {

private:

    static AssetManager* sAssetManager;

    std::map<std::string, SDL_Texture*> mTextures;

public:

    static AssetManager* Instance();
    static void Release();

    SDL_Texture* GetTexture(std::string file);

private:

    // Constructor
    AssetManager();
    // Deconstructor
    ~AssetManager();

};

#endif