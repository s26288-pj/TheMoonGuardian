#include "../Header Files/StartScreen.h"

StartScreen::StartScreen() {

    mTitle = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 42, SDL_Color ({255, 255, 255}));
    mTitle->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

    mPlayer = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
    mPlayer->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));

}

StartScreen::~StartScreen() {

    delete mTitle;
    mTitle = NULL;
}

void StartScreen::Update() {

    mPlayer->Update();
}

void StartScreen::Render() {

    mTitle->Render();
    mPlayer->Render();

}

//    mTexture = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
//    mTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
//
//    mText = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 42, SDL_Color({120, 100, 0}));
//    mText->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));