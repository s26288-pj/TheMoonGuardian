#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>
#include <string.h>
#include "MathHelper.h"

class InputManager {

private:

    static InputManager* sInputManager;

    Uint8* mPreviousKeyboardState;
    const Uint8* mKeyboardState;
    int mKeyLenght;

public:

    static InputManager* Instance();
    static void Release();

    bool KeyDown(SDL_Scancode scanCode);
    bool KeyPressed(SDL_Scancode scanCode);
    bool KeyReleased(SDL_Scancode scanCode);

    void Update();
    void UpdatePreviousInput();

private:

    // Contructor
    InputManager();
    // Deconstructor
    ~InputManager();

};

#endif