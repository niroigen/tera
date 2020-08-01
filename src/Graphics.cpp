#include "Graphics.hpp"

#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

namespace tera
{
  Graphics::Graphics(MessageBus* bus) : bus_(bus) {
    LOG("Built Graphics")
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow(
      GRAPHICS_SYSTEM,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      WIDTH,
      HEIGHT,
      0
    );

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_SOFTWARE);

    LOG("Built Graphics")
  }

  Graphics::~Graphics() {
    SDL_DestroyWindow(window_);
    SDL_Quit();
    LOG("Graphics Destroyed")
  }

  void Graphics::handleMessage(const char * message) {
    // TODO: Add logic to do stuff depending on message
  }
}


