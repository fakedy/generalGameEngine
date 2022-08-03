#include "InputManager.h"
#include "logger.h"


int InputManager::startUp() {

	return 1;
}



void InputManager::processInput(GLFWwindow *window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);



}
