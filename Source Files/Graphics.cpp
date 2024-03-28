#include "../Header Files/Graphics.h"

Graphics* Graphics::sGraphics = NULL;
bool Graphics::sInitialized = false;

// Create Graphics instance if it doesn't exist, otherwise return existing instance of Graphics
Graphics* Graphics::Instance() {

    if(sGraphics == NULL)
        sGraphics = new Graphics();

    return sGraphics;
}

// Delete Graphics and set sGraphics (pointer, type - Singleton) to NULL
void Graphics::Release() {

    delete sGraphics;
    sGraphics = NULL;

    sInitialized = false;
}

bool Graphics::Initialized() {

    return sInitialized;
}

// Constructor
Graphics::Graphics() {

    mBackBuffer = NULL;
    sInitialized = Init();
}

// Deconstructor
Graphics::~Graphics() {

    SDL_DestroyWindow(mWindow);
    mWindow = NULL;

    SDL_Quit();
}

bool Graphics::Init() {

    // Catch initialize errors and print them out in console
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {

       printf("SDL Initialization Error: %s\n", SDL_GetError());
       return false;
    }

    mWindow = SDL_CreateWindow(
            "Moon Guardian - The Awakening",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );

    // Catch window creation errors and print them out in console
    if(mWindow == NULL) {
        printf("Window creation error: %s\n", SDL_GetError());
        return false;
    }

    mBackBuffer = SDL_GetWindowSurface(mWindow);

    return true;
}

void Graphics::Render() {

    SDL_UpdateWindowSurface(mWindow);
}