#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "Graphics.h"

class GameManager {

private:

    static GameManager* sGameManager;

    bool mQuit;
    Graphics* mGraphics;

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