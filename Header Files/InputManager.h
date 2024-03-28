#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>

class InputManager {

private:

    static InputManager* sInputManager;

    const Uint8* mKeyboardStates;

public:

    static InputManager* Instance();
    static void Release();

    bool KeyDown(SDL_Scancode scancode);

    void Update();

private:

    // Contructor
    InputManager();
    // Deconstructor
    ~InputManager();

};

#endif