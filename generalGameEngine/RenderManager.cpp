#include "RenderManager.h"
#include "logger.h"
#include "GameObject.h"
#include"Shader.h"
#include "Framebuffer.h"
#include "UserInterface.h"
#include <vector>


	GLFWwindow* window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	// settings
	unsigned int SCR_WIDTH = 1920;
	unsigned int SCR_HEIGHT = 1080;

	unsigned int RENDER_WIDTH = 384;
	unsigned int RENDER_HEIGHT = 216;

	int RenderManager::startUp() {
	

	if (!glfwInit()) {
		Log(ERROR, "GLFW didnt load");
		return 0;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "generalGameEngine", NULL, NULL);
	if (!window) {
		Log(ERROR, "Window creation failed");
		shutDown();
		return 0;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// load glad

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Log(ERROR, "Glad did not load");
		shutDown();
		return 0;
	}

	// vsync 0 = off
	glfwSwapInterval(0);
	//glDepthFunc(GL_ALWAYS); // for future
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_CULL_FACE);



	if (!framebuffer_setup()) {
		Log(ERROR, "Framebuffer error");
		return 0;
	}




	ui_setup();


	return 1;

}

	void RenderManager::shutDown() {

		glfwTerminate();

	}


	void RenderManager::render(std::unordered_map<unsigned int, GameObject> gameobjects) {

		framebuffer_bind();
		

		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)
		// rendering
		glViewport(0, 0, RENDER_WIDTH, RENDER_HEIGHT);
		for (int i = 0; i < gameobjects.size(); i++){

		gameobjects[i].Draw();

		}

		


		framebuffer_render();

		ui_render(gameobjects);
		

		glfwSwapBuffers(window);

		glfwPollEvents();


	}

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		SCR_WIDTH = width;
		SCR_HEIGHT = height;
	}

