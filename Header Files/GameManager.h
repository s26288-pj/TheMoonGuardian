#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "StartScreen.h"


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

    StartScreen* mStartScreen;

public:

    static GameManager* Instance();
    static void Release();

    void Quit();
    void Run();

private:

    // Constructor
    GameManager();
    // Deconstructor
    ~GameManager();

    void EarlyUpdate();
    void Update();
    void LateUpdate();
    void Render();

};

#endif