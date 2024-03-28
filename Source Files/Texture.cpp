#include "../Header Files/Texture.h"

Texture::Texture(std::string path) {

    mGraphics = Graphics::Instance();

    mTexture = mGraphics->LoadTexture(path);
}

Texture::~Texture() {

    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mGraphics = NULL;
};

void Texture::Render() {

    mGraphics->DrawTexture(mTexture);
}