#ifndef MESSAGE_BUS_HPP
#define MESSAGE_BUS_HPP

#include <iostream>
#include "Core.hpp"
#include "System.hpp"

namespace tera {
  class MessageBus {
    public:
      void postMessage(const char * message);
      void addSystem(System * system);
    private:
      System * systems_[NUM_SYSTEMS];
      uint current_size_;
  };
}

#endif