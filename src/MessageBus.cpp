#include "MessageBus.hpp"

namespace tera {
  void MessageBus::postMessage(const char * message) {
    for (uint i = 0; i < current_size_; i++)
      systems_[i]->handleMessage(message);
  }

  void MessageBus::addSystem(System * system) {
    if (current_size_< NUM_SYSTEMS)
      systems_[current_size_++] = system;
  }
}