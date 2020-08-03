#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <iostream>
#include <thread>
#include <unordered_map>
#include "SDL.h"
#include "System.hpp"
#include "MessageBus.hpp"

#define WIDTH 640
#define HEIGHT 480
#define GRAPHICS_SYSTEM "Graphics System"
#define OFFSET 10

namespace tera {
  class Graphics : public System {
  public:
    Graphics(MessageBus* bus);
    ~Graphics();
    void initGraphics();
    void initMap();
    void handleMessage(const char * message); 
    void drawRect(uint x, uint y, uint w, uint h);
    void run();
    void draw();
    void clear();
    void increment(int& val);
    void decrement(int& val);
    bool isRunning = true;
  private:
    typedef void (Graphics::*f)(int&);
    struct Value {
      Value() {}
      Value(f f, int* val, const char * message, int dimension) : f_(f), val_(val), message_(message), dimension_(dimension) {}
      f f_;
      int* val_;
      const char * message_;
      int dimension_;
    };

    void keyInput(Value value);
    MessageBus* bus_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Rect r_;
    SDL_Event event_;
    std::thread t_;
    std::unordered_map<int, Value> map_;
  };
}

#endif