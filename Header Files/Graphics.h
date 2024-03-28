#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
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

    SDL_Renderer* mRenderer;

public:

    static Graphics* Instance();
    static void Release();
    static bool Initialized();

    SDL_Texture* LoadTexture(std::string path);

    void ClearBackBuffer();

    void DrawTexture(SDL_Texture* texture);

    void Render();

private:

    // Constructor
    Graphics();
    // Deconstructor
    ~Graphics();

    bool Init();
};

#endif