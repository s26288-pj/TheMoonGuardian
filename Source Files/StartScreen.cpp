#include "../Header Files/StartScreen.h"

StartScreen::StartScreen() {

    mTitle = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 62, SDL_Color ({200, 220, 255}));
    mTitle->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
    mTitle->Parent(this);

    mStart = new Texture("Start the game", "emulogic.ttf", 20, SDL_Color ({200, 220, 255}));
    mStart->Parent(mTitle);
    mStart->Position(Vector2(0, -160));

    mExit = new Texture("Exit", "emulogic.ttf", 20, SDL_Color ({200, 220, 255}));
    mExit->Parent(mTitle);
    mExit->Position(Vector2(0, -230));

    mPlayer = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
    mPlayer->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));
    mPlayer->Parent(this);

}

StartScreen::~StartScreen() {

    delete mTitle;
    mTitle = NULL;

    delete mStart;
    mStart = NULL;

    delete mExit;
    mExit = NULL;

    delete mPlayer;
    mPlayer = NULL;
}

void StartScreen::Update() {

    mPlayer->Update();
}

void StartScreen::Render() {

    mTitle->Render();
    mStart->Render();
    mExit->Render();
    mPlayer->Render();

}

//    mTexture = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
//    mTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
//
//    mText = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 42, SDL_Color({120, 100, 0}));
//    mText->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));