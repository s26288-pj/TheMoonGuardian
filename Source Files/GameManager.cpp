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

    mTimer = Timer::Instance();

    mTexture = new Texture("player.png", 17, 21, 15, 22);
    mTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

// Deconstructor
GameManager::~GameManager() {

    Graphics::Release();
    mGraphics = NULL;

    AssetManager::Release();
    mAssetManager = NULL;

    Timer::Release();
    mTimer = NULL;

    delete mTexture;
    mTexture = NULL;
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

            mGraphics->ClearBackBuffer();

            // Draw calls here
            mTexture->Render();

            mGraphics->Render();

            mTimer->Reset();
        }
    }
}