#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "GameEntity.h"
#include "Graphics.h"

class Texture : public GameEntity {

private:

    SDL_Texture* mTexture;

    Graphics* mGraphics;

public:

    // Constructor
    Texture(std::string path);
    // Deconstructor
    ~Texture();

    virtual void Render();
};

#endif