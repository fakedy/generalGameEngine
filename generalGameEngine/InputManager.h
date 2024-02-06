#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Commander.h"
#include"generalGameEngine.h"
#include"Scene.h"


void setCamera(Camera* cameraUsed);

class InputManager
{
public:
	static int startUp();

	//void setScene(Scene* sceneUsed);
	static void processInput(GLFWwindow* window, double deltaTime);
};
