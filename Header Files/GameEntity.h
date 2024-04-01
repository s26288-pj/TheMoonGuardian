#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include "MathHelper.h"

class GameEntity {

public:

    enum SPACE {local = 0, world = 1};

private:

    Vector2 mPosition;
    float mRotation;

    bool mActive;
    GameEntity* mParent;

public:

    // Constructor
    GameEntity(float x = 0.0f, float y = 0.0f);
    // Deconstructor
    ~GameEntity();

    void Position(Vector2 pos);
    Vector2 Position(SPACE space = world);

    void Rotation(float rotaion);
    float Rotation(SPACE space = world);

    void Active(bool active);
    bool Active();

    void Parent(GameEntity* parent);
    GameEntity* Parent();

    void Translate(Vector2 vector);

    virtual void Update();
    virtual void Render();
};

#endif