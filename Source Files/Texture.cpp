#include "../Header Files/Texture.h"

Texture::Texture(std::string filename) {

    mGraphics = Graphics::Instance();

    mTexture = AssetManager::Instance()->GetTexture(filename);

    SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);

    mClipped = false;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::Texture(std::string filename, int x, int y, int w, int h) {

    mGraphics = Graphics::Instance();

    mTexture = AssetManager::Instance()->GetTexture(filename);

    mClipped = true;
    mWidth = w;
    mHeight = h;

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;

    mClipRect.x = x;
    mClipRect.y = y;
    mClipRect.w = mWidth;
    mClipRect.h = mHeight;
}

Texture::~Texture() {

    mTexture = NULL;
    mGraphics = NULL;
};

void Texture::Render() {

    Vector2 position = Position(world);
    // This fragment makes sure our position is centered to center of our texture
    mRenderRect.x = (int)(position.x - mWidth * 0.5f);
    mRenderRect.y = (int)(position.y - mHeight * 0.5f);

    mGraphics->DrawTexture(mTexture, (mClipped)? &mClipRect : NULL, &mRenderRect);
}