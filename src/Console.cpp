#include "Console.hpp"

namespace tera {
  Console::Console(MessageBus* bus) : bus_(bus) {
    bus_->postMessage("Built console");
  }

  void Console::handleMessage(const char * message) {
    std::cout << message << std::endl;
  }
}