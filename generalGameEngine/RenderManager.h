#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include"GameObject.h"
#include<unordered_map>

	extern GLFWwindow* window;


	// settings
	extern unsigned int SCR_WIDTH;
	extern unsigned int SCR_HEIGHT;
	extern unsigned int RENDER_WIDTH;
	extern unsigned int RENDER_HEIGHT;


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
	static void render(std::unordered_map<unsigned int, GameObject> &gameobject);

};

