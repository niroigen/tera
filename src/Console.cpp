#include "Console.hpp"

#ifdef DEBUG
#define LOG(x) std::cout << "LOG: " << x << std::endl;
#else 
#define LOG(x)
#endif

namespace tera {
  Console::Console(MessageBus* bus) : bus_(bus) {
    LOG("Built console")
  }

  void Console::handleMessage(const char * message) {
    LOG("Incoming message")
    std::cout << message << std::endl;
  }
}