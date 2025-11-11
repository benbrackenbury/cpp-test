#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <string>
#include <vector>

std::vector<GLfloat> hexToRGBA(std::string hex) {
  std::vector<GLfloat> floats;
  if (hex[0] == '#') {
    hex.erase(0, 1);
  }
  for(int i = 0; i < hex.size() ; i+= 2) {
    std::string hexPart = hex.substr(i, 2);
    int chanValue = std::stoi(hexPart, nullptr, 16); // 0-255
    GLfloat floatChanValue = std::round((float(chanValue) / 255) * 10.0) / 10.0;
    floats.push_back(floatChanValue); 
  }
  floats.push_back(1.0f);  //alpha
  return floats;
}

class Window {
  public:
    Window(int width, int height, char* title, std::string bgColor) {
      this->width = width;
      this->height = height;
      this->title = title;
      this->bgColor = hexToRGBA(bgColor);
      this->window = this->create();
    }

    void loop() {
      while (!glfwWindowShouldClose(window)) {
          glfwPollEvents();
          glClear(GL_COLOR_BUFFER_BIT);
          glfwSwapBuffers(this->window);
      }
      glfwTerminate();
    }

  private:
    GLFWwindow* window;
    int width;
    int height;
    char* title;
    std::vector<GLfloat> bgColor;

    GLFWwindow* create() {
      glfwInit();
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      GLFWwindow* window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
      glfwMakeContextCurrent(window);
      glClearColor(this->bgColor[0], this->bgColor[1], this->bgColor[2], this->bgColor[3]);
      return window;
    }
};

int main() {
    Window window = Window(640, 800, "Test Window", "#f44000");
    window.loop();
    return 0;
}
