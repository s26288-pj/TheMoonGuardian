#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include "Graphics.h"
#include <map>

class AssetManager {

private:

    static AssetManager* sAssetManager;

    std::map<std::string, SDL_Texture*> mTextures;
    std::map<std::string, SDL_Texture*> mText;
    std::map<std::string, TTF_Font*> mFonts;

public:

    static AssetManager* Instance();
    static void Release();

    SDL_Texture* GetTexture(std::string file);
    SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

private:

    // Constructor
    AssetManager();
    // Deconstructor
    ~AssetManager();

    TTF_Font* GetFont(std::string filename, int size);

};

#endif