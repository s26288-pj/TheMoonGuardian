#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"
#include "Texture.h"
#include "InputManager.h"


class GameManager {

private:

    static GameManager* sGameManager;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics* mGraphics;
    AssetManager* mAssetManager;
    InputManager* mInputManager;

    Timer* mTimer;

    SDL_Event mEvent;

    Texture* mTexture;



public:

    static GameManager* Instance();
    static void Release();

    void Run();

private:

    // Constructor
    GameManager();
    // Deconstructor
    ~GameManager();
};

#endif