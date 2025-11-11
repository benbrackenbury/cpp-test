#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <string>
#include <vector>

class Window {
public:
  Window(int width, int height, char *title, std::string bgColor);
  void loop();

private:
  GLFWwindow *window;
  int width;
  int height;
  char *title;
  std::vector<GLfloat> bgColor;

  GLFWwindow *create();
  std::vector<GLfloat> hexToRGBA(std::string hex);
};

#endif
