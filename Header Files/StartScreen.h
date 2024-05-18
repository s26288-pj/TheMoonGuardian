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
    bool mPlayCallBack;

public:

    // Constructor
    StartScreen();
    //Deconstructor
    ~StartScreen();

    bool QuitCallBack();
    void QuitCallBack(bool b);

    bool PlayCallBack();
    void PlayCallBack(bool b);

    void Update();
    void Render();
};

#endif