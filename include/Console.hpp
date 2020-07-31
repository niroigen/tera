#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <iostream>
#include "System.hpp"
#include "MessageBus.hpp"

namespace tera {
  class Console : public System {
  public:
    Console(MessageBus* bus);
    void handleMessage(const char * message);
  private:
    MessageBus* bus_;
  };
}

#endif