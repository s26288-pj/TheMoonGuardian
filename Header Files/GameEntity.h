#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H

#include "MathHelper.h"

class GameEntity {

public:

    enum SPACE {local = 0, world = 1};

private:

    Vector2 mPosition;
    float mRotation;
    Vector2 mScale;

    bool mActive;
    GameEntity* mParent;

public:

    // Constructor
    GameEntity(Vector2 position = vec2_zero);
    // Deconstructor
    ~GameEntity();

    void Position(Vector2 pos);
    Vector2 Position(SPACE space = world);

    void Rotation(float rotation);
    float Rotation(SPACE space = world);

    void Scale(Vector2 scale);
    Vector2 Scale(SPACE space = world);

    void Active(bool active);
    bool Active();

    void Parent(GameEntity* parent);
    GameEntity* Parent();

    void Translate(Vector2 vector);
    void Rotate(float rotation_amount);

    virtual void Update();
    virtual void Render();
};

#endif