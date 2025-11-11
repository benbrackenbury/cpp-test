#include "Window.hpp"

int main() {
  Window window = Window(640, 800, "Test Window", "#f44000");
  window.loop();
  return 0;
}
