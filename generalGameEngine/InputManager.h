#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Commander.h"
#include"generalGameEngine.h"




class InputManager
{
public:
	static int startUp();
	static void processInput(GLFWwindow* window, Camera& camera, double deltaTime);
};
