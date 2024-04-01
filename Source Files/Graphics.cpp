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

    SDL_DestroyRenderer(mRenderer);
    mRenderer = NULL;

    IMG_Quit();
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

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    // Catch renderer creation errors and print them out in console
    if(mRenderer == NULL) {

        printf("Renderer creation error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

    int flags = IMG_INIT_PNG;
    // Catch image initialization errors
    if(!(IMG_Init(flags) & flags)) {

        printf("Image initialization error: %s\n", SDL_GetError());
        return false;
    }

    mBackBuffer = SDL_GetWindowSurface(mWindow);

    return true;
}

SDL_Texture* Graphics::LoadTexture(std::string path) {

    SDL_Texture* texture = NULL;

    SDL_Surface* surface = IMG_Load(path.c_str());
    // Catch image load errors
    if(surface == NULL) {

        printf("Image load error: %s\n", path.c_str(), SDL_GetError());
        return texture;
    }

    texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    // Catch texture creation errors
    if(texture == NULL) {

        printf("Create texture error: %s\n", SDL_GetError());
        return texture;
    }

    SDL_FreeSurface(surface);
    return texture;
}

void Graphics::ClearBackBuffer() {

    SDL_RenderClear(mRenderer);
}

void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* rend) {

    SDL_RenderCopy(mRenderer, texture, clip, rend);
}

void Graphics::Render() {

    SDL_RenderPresent(mRenderer);
}