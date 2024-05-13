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

//    if(mInputManager->KeyPressed(SDL_SCANCODE_SPACE)) {
//        printf("Space pressed\n");
//        mTexture->Translate(Vector2(0.0f, -120.0f) * mTimer->DeltaTime());
//    }
//    if(mInputManager->KeyDown(SDL_SCANCODE_LEFT)) {
//        printf("Left arrow pressed\n");
//        mTexture->Translate(Vector2(-220.0f, 0.0f) * mTimer->DeltaTime());
//    }
//    if(mInputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
//        printf("Right arrow pressed\n");
//        mTexture->Translate(Vector2(220.0f, 0.0f) * mTimer->DeltaTime());
//    }
//    if(mInputManager->MouseButtonPressed(InputManager::left)) {
//        printf("left mouse button pressed\n");
//    }

//    mTexture->Update();
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

        while(SDL_PollEvent(&mEvent) != 0) {

            if(mEvent.type == SDL_QUIT) {
                mQuit = true;
            }
        }

        // This allows us to limit frame rate of the window to value assigned in GameManager.h
        if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {

//            mInputManager->Update();
//
//            if(mInputManager->KeyDown(SDL_SCANCODE_SPACE)) {
//                mTexture->Translate(Vector2(0.0f, -120.0f) * mTimer->DeltaTime());
//            }
//            if(mInputManager->KeyDown(SDL_SCANCODE_LEFT)) {
//                mTexture->Translate(Vector2(-220.0f, 0.0f) * mTimer->DeltaTime());
//            }
//            if(mInputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
//                mTexture->Translate(Vector2(220.0f, 0.0f) * mTimer->DeltaTime());
//            }

            EarlyUpdate();
            Update();
            LateUpdate();
            Render();

        }
    }
}