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

Texture::Texture(std::string text, std::string fontpath, int size, SDL_Color color) {

    mGraphics = Graphics::Instance();
    mTexture = AssetManager::Instance()->GetText(text, fontpath, size, color);

    mClipped = false;

    SDL_QueryTexture(mTexture, NULL, NULL, & mWidth, &mHeight);

    mRenderRect.w = mWidth;
    mRenderRect.h = mHeight;
}

Texture::~Texture() {

    mTexture = NULL;
    mGraphics = NULL;
};

void Texture::Render() {

    Vector2 position = Position(world);
    Vector2 scale = Scale(world);
    // This fragment makes sure our position is centered to center of our texture
    mRenderRect.x = (int)(position.x - mWidth * 0.5f * scale.x);
    mRenderRect.y = (int)(position.y - mHeight * 0.5f * scale.y);
    mRenderRect.x = (int)(mWidth * scale.x);
    mRenderRect.y = (int)(mHeight * scale.y);

    mGraphics->DrawTexture(mTexture, (mClipped)? &mClipRect : NULL, &mRenderRect, Rotation(world));
}