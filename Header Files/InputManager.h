#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>
#include <string.h>
#include "MathHelper.h"

class InputManager {

public:
    enum MOUSE_BUTTON {left = 0, right, middle, back, forward};

private:

    static InputManager* sInputManager;

    Uint8* mPreviousKeyboardState;
    const Uint8* mKeyboardState;
    int mKeyLenght;

    Uint32 mPreviousMouseState;
    Uint32 mMouseState;

    int mMouseXPos;
    int mMouseYPos;

public:

    static InputManager* Instance();
    static void Release();

    bool KeyDown(SDL_Scancode scanCode);
    bool KeyPressed(SDL_Scancode scanCode);
    bool KeyReleased(SDL_Scancode scanCode);

    bool MouseButtonDown(MOUSE_BUTTON button);
    bool MouseButtonPressed(MOUSE_BUTTON button);
    bool MouseButtonReleased(MOUSE_BUTTON button);

    Vector2 MousePosition();

    void Update();
    void UpdatePreviousInput();

private:

    // Contructor
    InputManager();
    // Deconstructor
    ~InputManager();

};

#endif