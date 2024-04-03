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

    mTexture = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
    mTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

    mText = new Texture("Moon Guardian - The Awakening", "RadiantKingdom.ttf", 42, SDL_Color({120, 100, 0}));
    mText->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));
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

            mInputManager->Update();

            if(mInputManager->KeyDown(SDL_SCANCODE_SPACE)) {
                mTexture->Translate(Vector2(0.0f, -120.0f) * mTimer->DeltaTime());
            }
            if(mInputManager->KeyDown(SDL_SCANCODE_LEFT)) {
                mTexture->Translate(Vector2(-220.0f, 0.0f) * mTimer->DeltaTime());
            }
            if(mInputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
                mTexture->Translate(Vector2(220.0f, 0.0f) * mTimer->DeltaTime());
            }

            mTexture->Update();

            mGraphics->ClearBackBuffer();

            // Draw calls here
            mText->Render();
            mTexture->Render();

            mGraphics->Render();

            mTimer->Reset();
        }
    }
}