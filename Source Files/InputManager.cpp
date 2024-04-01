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

}

InputManager::~InputManager() {

}

bool InputManager::KeyDown(SDL_Scancode scancode) {

    return mKeyboardStates[scancode];
}

void InputManager::Update() {

    mKeyboardStates = SDL_GetKeyboardState(NULL);
}
