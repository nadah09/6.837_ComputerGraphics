#ifndef GLOO_INPUT_MANAGER_H_
#define GLOO_INPUT_MANAGER_H_

#include <functional>

#include "external.hpp"

namespace GLOO {
class InputManager {
 public:
  // Singleton design pattern.
  // InputManager is initialized the first time GetInstance is called.
  static InputManager& GetInstance() {
    static InputManager _instance;
    return _instance;
  }

  void SetWindow(GLFWwindow* window) {
    window_ = window;
  }

  InputManager(const InputManager&) = delete;
  void operator=(const InputManager&) = delete;

  // key should take values in
  // https://www.glfw.org/docs/latest/group__keys.html. Usually ASCII characters
  // are enough.
  bool IsKeyPressed(int key);

  bool IsKeyReleased(int key);

  glm::dvec2 GetCursorPosition();

  bool IsLeftMousePressed();
  bool IsRightMousePressed();
  bool IsMiddleMousePressed();

  glm::ivec2 GetWindowSize() const;

 private:
  InputManager() {
  }
  GLFWwindow* window_;
};
}  // namespace GLOO

#endif
