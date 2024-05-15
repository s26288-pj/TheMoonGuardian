#include "../Header Files/GameManager.h"

GameManager* GameManager::sGameManager = NULL;

// Create GameManager instance if it doesn't exist, otherwise return existing instance of GameManager
GameManager* GameManager::Instance() {

    if(sGameManager == NULL)
        sGameManager = new GameManager();

    return sGameManager;
}

// Delete GameManager and set sGameManager (pointer, type - Singleton) to NULL
void GameManager::Release() {

    delete sGameManager;
    sGameManager = NULL;
}

// Constructor
GameManager::GameManager() {

    mQuit = false;

    mGraphics = Graphics::Instance();

    // If something with Graphics initialization goes wrong we can exit the main loop by setting mQuit to true
    if(!Graphics::Initialized())
        mQuit = true;

    mAssetManager = AssetManager::Instance();

    mInputManager = InputManager::Instance();

    mTimer = Timer::Instance();

    mStartScreen = new StartScreen();

}

// Deconstructor
GameManager::~GameManager() {

    AssetManager::Release();
    mAssetManager = NULL;

    Graphics::Release();
    mGraphics = NULL;

    InputManager::Release();
    mInputManager = NULL;

    Timer::Release();
    mTimer = NULL;

    delete mStartScreen;
    mStartScreen = NULL;
}

void GameManager::EarlyUpdate() {

    mTimer->Reset();
    mInputManager->Update();
}

void GameManager::Update() {

    mStartScreen->Update();

}

void GameManager::Render() {

    mGraphics->ClearBackBuffer();

    // Draw calls here
    mStartScreen->Render();

    mGraphics->Render();
}

void GameManager::LateUpdate() {

    mInputManager->UpdatePreviousInput();
}


void GameManager::Run() {

    while(!mQuit) {

        mTimer->Update();

        if(mStartScreen->QuitCallback() == true)
            mQuit = true;

        while(SDL_PollEvent(&mEvent) != 0) {

            if(mEvent.type == SDL_QUIT) {
                mQuit = true;
            }
        }

        // This allows us to limit frame rate of the window to value assigned in GameManager.h
        if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {

            EarlyUpdate();
            Update();
            LateUpdate();
            Render();

        }
    }
}