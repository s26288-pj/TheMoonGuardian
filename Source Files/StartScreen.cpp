#include "../Header Files/StartScreen.h"

StartScreen::StartScreen() {

    mInputManager = InputManager::Instance();
    mQuitCall = false;

    mBackgroundTexture = new Texture("background.png");
    mBackgroundTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

    mTitle = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 86, SDL_Color ({200, 220, 255}));
    mTitle->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
    mTitle->Parent(this);

    mStart = new Texture("Start the game", "emulogic.ttf", 20, SDL_Color ({200, 220, 255}));
    mStart->Parent(mTitle);
    mStart->Position(Vector2(0, -160));

    mExit = new Texture("Exit", "emulogic.ttf", 20, SDL_Color ({200, 220, 255}));
    mExit->Parent(mTitle);
    mExit->Position(Vector2(0, -230));

//    mPlayer = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
//    mPlayer->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));
//    mPlayer->Parent(this);

    mSelector = new Texture("moon.png");
    mSelector->Parent(mStart);
    mSelector->Position(Vector2(-162.0f, 0.0f));

}

StartScreen::~StartScreen() {

    delete mBackgroundTexture;
    mBackgroundTexture = NULL;

    delete mTitle;
    mTitle = NULL;

    delete mStart;
    mStart = NULL;

    delete mExit;
    mExit = NULL;

    delete mSelector;
    mSelector = NULL;

}

bool StartScreen::QuitCallback() {

    return mQuitCall;
}

void StartScreen::QuitCallBack(bool b) {

    mQuitCall = b;
}

void StartScreen::Update() {

    mInputManager->Update();

    if(mInputManager->KeyDown(SDL_SCANCODE_UP)) {
        if(mStart != NULL)
            mSelector->Parent(mStart);
    }
    if(mInputManager->KeyDown(SDL_SCANCODE_DOWN)) {
        if(mExit != NULL)
            mSelector->Parent(mExit);
    }
    if(mInputManager->KeyDown(SDL_SCANCODE_RETURN)) {
        if(mSelector->Parent() == mExit) {
            QuitCallBack(true);
        }
        if(mSelector->Parent() == mStart) {
            StartScreen::~StartScreen();
        }
    }
}

void StartScreen::Render() {

    mBackgroundTexture->Render();
    mTitle->Render();
    mStart->Render();
    mExit->Render();
    mSelector->Render();

}