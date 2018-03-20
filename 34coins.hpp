#ifndef _34COINS_H
#define _34COINS_H

#include <iostream>

#include "SDL2/SDL.h"

const auto SCREEN_WIDTH = 320;
const auto SCREEN_HEIGHT = 240;
const auto WINDOW_TITLE = "34 Coins For My Kingdom";

class MainWindow {
  public:
    MainWindow();
    ~MainWindow();

  private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif