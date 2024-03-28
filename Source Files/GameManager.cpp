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

GameManager::GameManager() {

    mQuit = false;

    mGraphics = Graphics::Instance();

    // If something with Graphics initialization goes wrong we can exit the main loop by setting mQuit to true
    if(!Graphics::Initialized())
        mQuit = true;
}

GameManager::~GameManager() {

    Graphics::Release();
    mGraphics = NULL;
}

void GameManager::Run() {

    while(!mQuit) {

        while(SDL_PollEvent(&mEvent) != 0) {

            if(mEvent.type == SDL_QUIT) {
                mQuit = true;
            }

            mGraphics -> Render();
        }
    }
}