#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <cstdio>

class Graphics {

public:

    static const int SCREEN_WIDTH = 1280;
    static const int SCREEN_HEIGHT = 720;

private:

    static Graphics* sGraphics;
    static bool sInitialized;

    SDL_Window* mWindow;
    SDL_Surface* mBackBuffer;

public:

    static Graphics* Instance();
    static void Release();
    static bool Initialized();

    void Render();

private:

    // Constructor
    Graphics();
    // Deconstructor
    ~Graphics();

    bool Init();
};

#endif