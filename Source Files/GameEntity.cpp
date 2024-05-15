#include "../Header Files/GameEntity.h"

// Constructor
GameEntity::GameEntity(Vector2 position) {

    mPosition = position;

    mRotation = 0.0f;

    mActive = true;

    mParent = NULL;

    mScale = vec2_one;
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

    Vector2 parentScale = mParent->Scale(world);
    Vector2 rotatedPosition = RotateVector(Vector2(mPosition.x * parentScale.x, mPosition.y * parentScale.y), mParent->Rotation(local));

    return mParent->Position(world) + rotatedPosition;
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

// Setter of mScale
void GameEntity::Scale(Vector2 scale) {

    mScale = scale;
}

// Getter of mScale
Vector2 GameEntity::Scale(SPACE space) {

    if(space == local || mParent == NULL)
        return mScale;

    Vector2 scale = mParent->Scale(world);
    scale.x *= mScale.x;
    scale.y *= mScale.y;

    return scale;
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

    if(parent == NULL) {
        mPosition = Position(world);
        mRotation = Rotation(world);
        mScale = Scale(world);
    }
    else {

        Vector2 parentScale = parent->Scale(world);

        mPosition = RotateVector(Position(world) - parent->Position(world), (float)(-parent->Rotation(world)));
        mPosition.x /= parentScale.x;
        mPosition.y /= parentScale.y;

        mRotation = parent->Rotation(world);

        mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
    }

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

void GameEntity::Translate(Vector2 vector) {

    mPosition += vector;
}

void GameEntity::Rotate(float rotation_amount) {

    mRotation += rotation_amount;
}