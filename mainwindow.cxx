#include "34coins.hpp"

MainWindow::MainWindow() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    goto sdl_err;
  }

  window = SDL_CreateWindow(
      WINDOW_TITLE,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH, SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN
  );

  if (!window) {
    goto sdl_err;
  }

  renderer = SDL_CreateRenderer(
      window,
      -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  if (!renderer) {
    sdl_err:
      throw "Unable to initialize SDL";
  }
}

MainWindow::~MainWindow() {
  if (renderer) {
    SDL_DestroyRenderer(renderer);
  }

  if (window) {
    SDL_DestroyWindow(window);
  }

  SDL_Quit();
}

