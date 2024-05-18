#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H

#include "InputManager.h"
#include "AnimatedTexture.h"
#include "Player.h"

class PlayScreen {

private:

    InputManager* mInputManager;

    Player* mPlayer;

public:

    // Constructor
    PlayScreen();
    // Deconstructor
    ~PlayScreen();

    void Update();
    void Render();
};

#endif
