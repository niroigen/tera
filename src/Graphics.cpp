#include "Graphics.hpp"

namespace tera
{
  Graphics::Graphics(MessageBus* bus) : bus_(bus) {
    bus_->postMessage("Building Graphics");
    initGraphics();

    drawRect(100,100, 40, 50);

    t_ = std::thread(&Graphics::run, this);

    initMap();

    bus_->postMessage("Built Graphics");
  }

  Graphics::~Graphics() {
    t_.join();
    SDL_DestroyWindow(window_);
    SDL_Quit();
  }

  void Graphics::initGraphics() {
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
  }

  void Graphics::initMap() {
    map_.emplace(SDLK_LEFT, Value(&Graphics::decrement, &r_.x, "Left Key", WIDTH));
    map_.emplace(SDLK_RIGHT, Value(&Graphics::increment, &r_.x, "Right Key", WIDTH));
    map_.emplace(SDLK_UP, Value(&Graphics::decrement, &r_.y, "Up Key", HEIGHT));
    map_.emplace(SDLK_DOWN, Value(&Graphics::increment, &r_.y, "Down Key", HEIGHT));
  }

  void Graphics::increment(int& val) {
    val += OFFSET;
  }

  void Graphics::decrement(int& val) {
    val -= OFFSET;
  }

  void Graphics::keyInput(Value value) {
    bus_->postMessage(value.message_);
    (this->*value.f_)(*value.val_);
    *value.val_ %= value.dimension_;
    draw();
  }

  void Graphics::run() {
    while(isRunning) {
      while(SDL_PollEvent(&event_) != 0) {
        switch( event_.type ){
          case SDL_QUIT:
            bus_->postMessage("Killing the engine");
            isRunning = false;
            break;
          case SDL_KEYDOWN:
            if (map_.find(event_.key.keysym.sym) != map_.end())
              keyInput(map_[event_.key.keysym.sym]);
            break;
          default:
            break;
        }
      }
    }
  }

  void Graphics::drawRect(uint x, uint y, uint w, uint h) {
    r_.x = x;
    r_.y = y;
    r_.w = w;
    r_.h = h;
    draw();
  }

  void Graphics::draw() {
    clear();
    SDL_SetRenderDrawColor( renderer_, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer_, &r_);
    SDL_RenderPresent(renderer_);
  }

  void Graphics::clear() {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer_);
  }

  void Graphics::handleMessage(const char * message) {
  }
}


