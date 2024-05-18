#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <cstdio>
#include <vector>

class Graphics {

public:

    static const int SCREEN_WIDTH = 1280;
    static const int SCREEN_HEIGHT = 720;
    static const int TILE_WIDTH = 32;
    static const int TILE_HEIGHT = 32;

private:

    static Graphics* sGraphics;
    static bool sInitialized;

    SDL_Window* mWindow;
    SDL_Surface* mBackBuffer;

    SDL_Renderer* mRenderer;

    SDL_Surface* mBitmap;
    SDL_Texture* mTiles;
    std::vector<SDL_Point> mCollisionPoints;

public:

    static Graphics* Instance();
    static void Release();
    static bool Initialized();

    SDL_Texture* LoadTexture(std::string path);
    SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

    void ClearBackBuffer();

    void DrawTexture(SDL_Texture* texture, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL,
                     float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void DrawLevelFromBitmap(std::string bitmap, std::string tiles, int w, int h);
    SDL_Color GetPixelColor(int x, int y);
    void ScaleBitmap(std::string originalPath, std::string newPath, int scale);

    void Render();

private:

    // Constructor
    Graphics();
    // Deconstructor
    ~Graphics();

    bool Init();
};

#endif