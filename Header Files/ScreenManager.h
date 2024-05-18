#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "StartScreen.h"
#include "PlayScreen.h"

class ScreenManager {

private:

    enum SCREENS {start, play};

    static ScreenManager* sInstance;

    InputManager* mInputManager;

    StartScreen* mStartScreen;
    PlayScreen* mPlayScreen;

    SCREENS mCurrentScreen;

public:

    static ScreenManager* Instance();
    static void Release();

    bool QuitTrigger();

    void Update();
    void Render();

private:

    // Constructor
    ScreenManager();
    ~ScreenManager();
};

#endif
