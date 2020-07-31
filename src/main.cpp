#include "Console.hpp"
#include "MessageBus.hpp"

int main() {
  tera::MessageBus* bus = new tera::MessageBus();
  tera::Console* console = new tera::Console(bus);
  bus->addSystem(console);

  // Testing saying hi

  bus->postMessage("Hello World");

  delete console;
  delete bus;
}