#include "Console.hpp"
#include "Graphics.hpp"
#include "MessageBus.hpp"

int main() {
  tera::MessageBus* bus = new tera::MessageBus();
  tera::Console* console = new tera::Console(bus);
  tera::Graphics* graphics = new tera::Graphics(bus);
  bus->addSystem(console);
  bus->addSystem(graphics);
  // Testing saying hi

  bus->postMessage("Hello World");

  delete console;
  delete graphics;
  delete bus;
}