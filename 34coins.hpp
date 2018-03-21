#ifndef _34COINS_H
#define _34COINS_H

#include <iostream>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

const auto SCREEN_WIDTH = 320;
const auto SCREEN_HEIGHT = 300;
const auto MIN_FPS = 16;
const auto WINDOW_TITLE = "34 Coins For My Kingdom";

class MainWindow {
  public:
    MainWindow();
    ~MainWindow();
    void start();
    bool walletIsFull = false;

  private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture *bg = nullptr;
    SDL_Texture *walletEmpty = nullptr;
    SDL_Texture *walletFull = nullptr;
    SDL_Rect bgRect;

    void renderBg();
    void renderWallet();
};

void add34Coins(bool fill);

#endif