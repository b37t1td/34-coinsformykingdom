#include "34coins.hpp"

#include "images/bg.h"
#include "images/empty.h"
#include "images/full.h"

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

void MainWindow::start() {
  bool running = true;

  bg = SDL_CreateTextureFromSurface(renderer,
      IMG_LoadTyped_RW(SDL_RWFromConstMem(bgImage, sizeof(bgImage)), true, "PNG"));

  walletEmpty = SDL_CreateTextureFromSurface(renderer,
      IMG_LoadTyped_RW(SDL_RWFromConstMem(emptyWalletImage, sizeof(emptyWalletImage)), true, "PNG"));

  walletFull = SDL_CreateTextureFromSurface(renderer,
      IMG_LoadTyped_RW(SDL_RWFromConstMem(fullWalletImage, sizeof(fullWalletImage)), true, "PNG"));

  //While application is running
  while(running) {

    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)
        return;
      else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
        return;
      else if (e.type == SDL_MOUSEBUTTONDOWN) {
        walletIsFull = !walletIsFull;
        break;
      }
    }

    SDL_RenderClear(renderer);
    renderBg();
    renderWallet();
    SDL_RenderPresent(renderer);
  }
}

void MainWindow::renderWallet() {
  SDL_Rect wRect;
  wRect.h = bgRect.h / 2;
  wRect.w = bgRect.w / 3;
  wRect.x = bgRect.w - (wRect.w + 20);
  wRect.y = 20;

  if (walletIsFull) {
    SDL_RenderCopy(renderer, walletFull, NULL, &wRect);
  } else {
    SDL_RenderCopy(renderer, walletEmpty, NULL, &wRect);
  }
}

void MainWindow::renderBg() {
  bgRect.x = 0;
  bgRect.y = 0;
  bgRect.w = SDL_GetWindowSurface(window)->w;
  bgRect.h = SDL_GetWindowSurface(window)->h;

  SDL_RenderCopy(renderer, bg, NULL, &bgRect);
}
