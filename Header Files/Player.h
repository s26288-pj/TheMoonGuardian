#ifndef _PLAYER_H
#define _PLAYER_H

#include "AnimatedTexture.h"
#include "InputManager.h"

class Player : public GameEntity {

private:

    Timer* mTimer;
    InputManager* mInputManager;

    bool mVisible;
    bool mJumping = false;
    float mJumpVelocity = 180.0f;
    float mGravity = 40.0f;
    Vector2 mVelocity;

    AnimatedTexture* mPlayer;

    float mMovementSpeed;

public:

    Player();
    ~Player();

    void Visible(bool vis);
    bool Visible();

    void Update();
    void Render();

    Vector2 CheckCollisionOffset();

private:

    void HandleMovement();
    void Gravity();

};

#endif

