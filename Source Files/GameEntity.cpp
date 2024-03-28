#include "../Header Files/GameEntity.h"

// Constructor
GameEntity::GameEntity(float x, float y) {

    mPosition.x = x;
    mPosition.y = y;

    mRotation = 0.0f;

    mActive = true;

    mParent = NULL;
}

// Deconstructor
GameEntity::~GameEntity() {

    mParent = NULL;
}

// Setter of mPosition
void GameEntity::Position(Vector2 pos) {

    mPosition = pos;
}

// Getter of mPosition
Vector2 GameEntity::Position(SPACE space) {

    if(space == local || mParent == NULL)
        return mPosition;

    return mParent->Position(world) + RotateVector(mPosition, mParent->Rotation(local));
}

// Setter of mRotation
void GameEntity::Rotation(float rotation) {

    mRotation = rotation;

    if(mRotation > 360.0f)
        mRotation -= 360.0f;

    if(mRotation < 0.0f)
        mRotation += 360.0f;
}

// Getter of mRotation
float GameEntity::Rotation(SPACE space) {

    if(space == local || mParent == NULL)
        return mRotation;

    return mParent->Rotation(world) + mRotation;
}

// Setter of mActive
void GameEntity::Active(bool active) {

    mActive = active;
}

// Getter of mActive
bool GameEntity::Active() {

    return mActive;
}

// Setter of parent to the child object
void GameEntity::Parent(GameEntity* parent) {

    mPosition = Position(world) - parent->Position(world);
    mParent = parent;
}

// Getter of parent object
GameEntity* GameEntity::Parent() {

    return mParent;
}

void GameEntity::Update() {

}

void GameEntity::Render() {

}