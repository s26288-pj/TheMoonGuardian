#include "../Header Files/ScreenManager.h"


ScreenManager* ScreenManager::sInstance = NULL;

// Create GameManager instance if it doesn't exist, otherwise return existing instance of GameManager
ScreenManager* ScreenManager::Instance() {

    if(sInstance == NULL)
        sInstance = new ScreenManager();

    return sInstance;
}

void ScreenManager::Release() {

    delete sInstance;
    sInstance = NULL;
}

ScreenManager::ScreenManager() {

    mInputManager = InputManager::Instance();

    mStartScreen = new StartScreen();
    mPlayScreen = new PlayScreen();

    mCurrentScreen = start;
}

ScreenManager::~ScreenManager() {

    mInputManager = NULL;

    delete mStartScreen;
    mStartScreen = NULL;

    delete mPlayScreen;
    mPlayScreen = NULL;
}

void ScreenManager::Update() {

    switch(mCurrentScreen) {

        case start:
            mStartScreen->Update();
            break;

        case play:
            mPlayScreen->Update();
            break;

    }
}

void ScreenManager::Render() {

    if(mStartScreen->PlayCallBack() == true)
        mCurrentScreen = play;

    switch(mCurrentScreen) {

        case start:
            mStartScreen->Render();
            break;

        case play:
            mPlayScreen->Render();
            break;
    }
}

bool ScreenManager::QuitTrigger() {

    return mStartScreen->QuitCallBack();
}
