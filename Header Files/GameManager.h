#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Graphics.h"
#include "Timer.h"

class GameManager {

private:

    static GameManager* sGameManager;

    const int FRAME_RATE = 60;

    bool mQuit;
    Graphics* mGraphics;

    Timer* mTimer;

    SDL_Event mEvent;

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