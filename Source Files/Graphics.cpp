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

    TTF_Quit();
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

    // Setting the renderer's clear color to black
    SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0x00);

    int flags = IMG_INIT_PNG;
    // Catch image initialization errors
    if(!(IMG_Init(flags) & flags)) {

        printf("Image initialization error: %s\n", SDL_GetError());
        return false;
    }

    if(TTF_Init() == -1) {

        printf("TTF Initialization error: %s\n", TTF_GetError());
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

void Graphics::DrawLevelFromBitmap(std::string bitmap_path, std::string tiles_path, int tile_w, int tile_h) {

    SDL_Surface* mBitmap = IMG_Load(bitmap_path.c_str());
    SDL_Texture* mTiles = Graphics::Instance()->LoadTexture(tiles_path);

    if(mBitmap == NULL) {

        printf("Image load error: %s\n", bitmap_path.c_str(), SDL_GetError());
    }

    SDL_Rect tileClips[24];
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 8; ++col) {
            int index = row * 8 + col;
            tileClips[index] = { col * tile_w, row * tile_h, tile_w, tile_h };
        }
    }

    for (int y = 0; y < mBitmap->h; ++y) {
        for (int x = 0; x < mBitmap->w; ++x) {
            Uint32 pixel = ((Uint32*)mBitmap->pixels)[y * mBitmap->pitch / 4 + x];
            Uint8 r, g, b;
            SDL_GetRGB(pixel, mBitmap->format, &r, &g, &b);

            SDL_Rect* tile = &tileClips[19];

            if (r == 0 && g == 0 && b == 0) {
                SDL_Rect renderQuad = { x * tile_w, y * tile_h, tile_w, tile_h };
                SDL_RenderCopy(mRenderer, mTiles, tile, &renderQuad);
            }
            else {
                SDL_Rect renderQuad = { x * tile_w, y * tile_h, tile_w, tile_h };
                SDL_RenderCopy(mRenderer, mTiles, &tileClips[11], &renderQuad);
            }
        }
    }
}

void Graphics::ScaleBitmap(std::string originalPath, std::string newPath, int scale) {
    // Load the original bitmap
    SDL_Surface* originalSurface = IMG_Load(originalPath.c_str());
    if (originalSurface == nullptr) {
        printf("Failed to load original bitmap: %s\n", IMG_GetError());
        return;
    }

    // Create a new bitmap surface that is scaled
    SDL_Surface* scaledSurface = SDL_CreateRGBSurface(0, originalSurface->w * scale, originalSurface->h * scale, 32,
                                                      0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    if (scaledSurface == nullptr) {
        printf("Failed to create scaled bitmap surface: %s\n", SDL_GetError());
        SDL_FreeSurface(originalSurface);
        return;
    }

    // Scale the bitmap
    for (int y = 0; y < originalSurface->h; ++y) {
        for (int x = 0; x < originalSurface->w; ++x) {
            Uint32 pixel = ((Uint32*)originalSurface->pixels)[y * originalSurface->pitch / 4 + x];
            Uint8 r, g, b, a;
            SDL_GetRGBA(pixel, originalSurface->format, &r, &g, &b, &a);
            // If the pixel is black (solid), set it to black in the scaled bitmap, otherwise set it to white
            Uint32 newPixel = (r == 0 && g == 0 && b == 0) ? SDL_MapRGBA(scaledSurface->format, 0, 0, 0, 255) :
                              SDL_MapRGBA(scaledSurface->format, 255, 255, 255, 255);
            for (int dy = 0; dy < scale; ++dy) {
                for (int dx = 0; dx < scale; ++dx) {
                    ((Uint32*)scaledSurface->pixels)[(y * scale + dy) * scaledSurface->pitch / 4 + (x * scale + dx)] = newPixel;
                }
            }
        }
    }

    // Save the scaled bitmap
    if (IMG_SavePNG(scaledSurface, newPath.c_str()) < 0) {
        printf("Failed to save scaled bitmap: %s\n", IMG_GetError());
    }

    // Free surfaces
    SDL_FreeSurface(originalSurface);
    SDL_FreeSurface(scaledSurface);
}

SDL_Color Graphics::GetPixelColor(int x, int y) {
    ScaleBitmap("../Assets/sprites/bitmap.bmp", "../Assets/sprites/bitmap_full.bmp", 16);
    SDL_Surface* bitmapSurface = IMG_Load("../Assets/sprites/bitmap_full.bmp");
    Uint32 pixel = ((Uint32*)bitmapSurface->pixels)[(y * bitmapSurface->pitch / 4) + x];
    SDL_Color color;
    SDL_GetRGB(pixel, bitmapSurface->format, &color.r, &color.g, &color.b);
    SDL_FreeSurface(bitmapSurface);
    return color;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    // Catch text render errors
    if(surface == NULL) {

        printf("Text render error: %s\n", TTF_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    // Catch text texture creation errors
    if(texture == NULL) {

        printf("Text texture creation error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(surface);

    return texture;
}

void Graphics::ClearBackBuffer() {

    SDL_RenderClear(mRenderer);
}

void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {

    SDL_RenderCopyEx(mRenderer, texture, clip, rend, angle, NULL, flip);
}

void Graphics::Render() {

    SDL_RenderPresent(mRenderer);
}