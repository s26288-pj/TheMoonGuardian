#include "../Header Files/AssetManager.h"

AssetManager* AssetManager::sAssetManager = NULL;

AssetManager* AssetManager::Instance() {

    if(sAssetManager == NULL)
        sAssetManager = new AssetManager();

    return sAssetManager;
}

void AssetManager::Release() {

    delete sAssetManager;
    sAssetManager = NULL;
}

// Constructor
AssetManager::AssetManager() {

}

// Deconstructor
AssetManager::~AssetManager() {

    for(auto tex : mTextures) {
        if(tex.second != NULL) {
            SDL_DestroyTexture(tex.second);
        }
    }

    mTextures.clear();
}

SDL_Texture* AssetManager::GetTexture(std::string file) {

    std::string fullPath = SDL_GetBasePath();
    fullPath.append("../Assets/" + file);

    if(mTextures[fullPath] == nullptr)
        mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);

    return mTextures[fullPath];
}