#include "../Header Files/PlayScreen.h"

PlayScreen::PlayScreen() {

    mInputManager = InputManager::Instance();

    mPlayer = new Player();
    mPlayer->Visible(true);

}

PlayScreen::~PlayScreen() {

    mInputManager = NULL;

    delete mPlayer;
    mPlayer = NULL;

}

void PlayScreen::Update() {

    mPlayer->Update();
}

void PlayScreen::Render() {

    Graphics::Instance()->DrawLevelFromBitmap("../Assets/sprites/bitmap.bmp", "../Assets/sprites/platformertiles.png", 32, 32);
    mPlayer->Render();
}
