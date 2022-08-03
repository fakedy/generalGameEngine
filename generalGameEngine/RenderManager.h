#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

	extern GLFWwindow* window;


class RenderManager
{

public:
	
	RenderManager() {
		// do nothing
	}
	~RenderManager() {
		// do nothing
	}

	static int startUp();
	static void shutDown();
	static void render();

};

