#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include"GameObject.h"

	extern GLFWwindow* window;

	// settings
	extern const unsigned int SCR_WIDTH;
	extern const unsigned int SCR_HEIGHT;


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
	static void render(std::vector<GameObject> gameobjects);

};

