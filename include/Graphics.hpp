#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include "SDL.h"
#include "System.hpp"
#include "MessageBus.hpp"

#define WIDTH 640
#define HEIGHT 480
#define GRAPHICS_SYSTEM "Graphics System"

namespace tera {
  class Graphics : public System {
  public:
    Graphics(MessageBus* bus);
    ~Graphics();
    void handleMessage(const char * message);
  private:
    MessageBus* bus_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
  };
}

#endif