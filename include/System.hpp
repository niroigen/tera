#ifndef SYSTEM_HPP
#define SYSTEM_HPP

namespace tera {
  class System {
    public:
      virtual void handleMessage(const char * message) = 0;
  };
}

#endif