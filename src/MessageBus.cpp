#include "MessageBus.hpp"
#ifdef DEBUG
#define LOG(x) std::cout << "LOG: " << x << std::endl;
#else 
#define LOG(x)
#endif

namespace tera {
  void MessageBus::postMessage(const char * message) {
    LOG("Posting message")
    for (uint i = 0; i < current_size_; i++) {
        systems_[i]->handleMessage(message);
    }
    LOG("Message posted")
  }

  void MessageBus::addSystem(System * system) {
    LOG("Adding system")
    if (current_size_< NUM_SYSTEMS) {
      systems_[current_size_++] = system;
    }
    LOG("System added to bus")
  }
}