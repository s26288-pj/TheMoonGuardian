#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include <functional>
#include "AnimatedTexture.h"
#include "InputManager.h"

class StartScreen : public GameEntity {

private:

    Timer* mTimer;
    InputManager* mInputManager;

    Texture* mBackgroundTexture;
    Texture* mTitle;
    Texture* mStart;
    Texture* mExit;
    Texture* mSelector;

    bool mQuitCall;

public:

    // Constructor
    StartScreen();
    //Deconstructor
    ~StartScreen();

    void QuitCallBack(bool b);
    bool QuitCallback();
    void Update();
    void Render();
};

#endif