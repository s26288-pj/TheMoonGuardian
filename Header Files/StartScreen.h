#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"

class StartScreen : public GameEntity {

private:

    Texture* mTitle;
    AnimatedTexture* mPlayer;


public:

    // Constructor
    StartScreen();
    //Deconstructor
    ~StartScreen();

    void Update();
    void Render();
};

#endif
