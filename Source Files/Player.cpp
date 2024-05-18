#include "../Header Files/Player.h"

Player::Player() {

    mTimer = Timer::Instance();
    mInputManager = InputManager::Instance();

    mVisible = false;
    mMovementSpeed = 100.0f;

    mPlayer = new AnimatedTexture("player.png", 0, 64, 48, 26, 6, 1.0f, AnimatedTexture::horizontal);
    mPlayer->Position(Vector2(50.0f, Graphics::Instance()->SCREEN_HEIGHT - 120.0f));
}

Player::~Player() {

    mTimer = NULL;
    mInputManager = NULL;
}


void Player::HandleMovement() {

    if (mInputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
        mVelocity.x = mMovementSpeed;
    }
    else if (mInputManager->KeyDown(SDL_SCANCODE_LEFT)) {
        mVelocity.x = -mMovementSpeed;
    }
    else {
        mVelocity.x = 0.0f;
    }

    if (mInputManager->KeyPressed(SDL_SCANCODE_SPACE) && !mJumping) {
        mJumping = true;
        mVelocity.y = -mJumpVelocity;
    }

    Vector2 collisionOffset = CheckCollisionOffset();

    if (collisionOffset.y != 0.0f) {
        if (mVelocity.y > 0.0f) {
            mVelocity.y = 0.0f;
            mJumping = false;
            mPlayer->Position(Vector2(mPlayer->Position().x, mPlayer->Position().y - collisionOffset.y));
        }
    }

    if (collisionOffset.x != 0.0f) {
        mVelocity.x = 0.0f;
    }

    Vector2 pos = mPlayer->Position();
    pos += mVelocity * mTimer->DeltaTime() + collisionOffset;
    mPlayer->Position(pos);
}

void Player::Update() {

    Gravity();
    HandleMovement();
    mPlayer->Update();
}

Vector2 Player::CheckCollisionOffset() {
    // Get the player's position and calculate the bitmap coordinates
    Vector2 playerPos = mPlayer->Position(world);
    int bitmapX = static_cast<int>(playerPos.x / 2);
    int bitmapY = static_cast<int>(playerPos.y / 2);

    Vector2 collisionOffset(0.0f, 0.0f);

    // Check for collisions and adjust offset accordingly
    if (Graphics::Instance()->GetPixelColor(bitmapX - 4, bitmapY).r == 0) {
        collisionOffset.x += 2.8f; // Adjust this value based on player size
    }
    if (Graphics::Instance()->GetPixelColor(bitmapX + 4, bitmapY).r == 0) {
        collisionOffset.x -= 2.8f; // Adjust this value based on player size
    }
    if (Graphics::Instance()->GetPixelColor(bitmapX, bitmapY - 4).r == 0) {
        collisionOffset.y += 2.8f; // Adjust this value based on player size
    }
    if (Graphics::Instance()->GetPixelColor(bitmapX, bitmapY + 4).r == 0) {
        collisionOffset.y -= 2.8f; // Adjust this value based on player size
    }

    return collisionOffset;
}

void Player::Gravity() {

    mVelocity.y -= (-1.0f * mTimer->DeltaTime() * mGravity * 5.0f);
}

void Player::Visible(bool vis) {

    mVisible = vis;
}

bool Player::Visible() {

    return mVisible;
}


void Player::Render() {

    if(mVisible)
        mPlayer->Render();
}