#include "../Header Files/InputManager.h"

// Create InputManager instance if it doesn't exist, otherwise return existing instance of InputManager
InputManager* InputManager::sInputManager = NULL;

InputManager* InputManager::Instance() {

    if(sInputManager == NULL)
        sInputManager = new InputManager();

    return sInputManager;
}

// Delete InputManager and set sInputManager (pointer, type - Singleton) to NULL
void InputManager::Release() {
    delete sInputManager;
    sInputManager = NULL;
}

InputManager::InputManager() {

    mKeyboardState = SDL_GetKeyboardState(&mKeyLenght);
    mPreviousKeyboardState = new Uint8[mKeyLenght];
    memcpy(mPreviousKeyboardState, mKeyboardState, mKeyLenght);
}

InputManager::~InputManager() {

    delete[] mPreviousKeyboardState;
    mPreviousKeyboardState = NULL;
}

bool InputManager::KeyDown(SDL_Scancode scancode) {

    return (mKeyboardState[scancode] != 0);
}

bool InputManager::KeyPressed(SDL_Scancode scanCode) {

    return (mPreviousKeyboardState[scanCode]) == 0 && (mKeyboardState[scanCode] != 0);
}

bool InputManager::KeyReleased(SDL_Scancode scanCode) {

    return (mPreviousKeyboardState[scanCode]) != 0 && (mKeyboardState[scanCode] == 0);
}

void InputManager::Update() {

}

void InputManager::UpdatePreviousInput() {

    memcpy(mPreviousKeyboardState, mKeyboardState, mKeyLenght);
}
