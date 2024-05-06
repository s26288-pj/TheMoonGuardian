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

Vector2 InputManager::MousePosition() {

    return Vector2((float)mMouseXPos, (float)mMouseYPos);
}

bool InputManager::MouseButtonDown(InputManager::MOUSE_BUTTON button) {

    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;
        case right:
            mask = SDL_BUTTON_RMASK;
            break;
        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case forward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }

    return (mMouseState & mask);
}

bool InputManager::MouseButtonPressed(InputManager::MOUSE_BUTTON button) {

    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;
        case right:
            mask = SDL_BUTTON_RMASK;
            break;
        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case forward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }

    return !(mPreviousMouseState & mask) && (mMouseState & mask);
}

bool InputManager::MouseButtonReleased(InputManager::MOUSE_BUTTON button) {

    Uint32 mask = 0;

    switch (button) {
        case left:
            mask = SDL_BUTTON_LMASK;
            break;
        case right:
            mask = SDL_BUTTON_RMASK;
            break;
        case middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case forward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }

    return (mPreviousMouseState & mask) && !(mMouseState & mask);
}

void InputManager::Update() {

    mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
}

void InputManager::UpdatePreviousInput() {

    memcpy(mPreviousKeyboardState, mKeyboardState, mKeyLenght);
    mPreviousMouseState = mMouseState;
}
