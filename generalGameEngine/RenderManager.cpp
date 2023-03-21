#include "RenderManager.h"
#include "logger.h"
#include "GameObject.h"
#include <vector>


	GLFWwindow* window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	// settings
	const unsigned int SCR_WIDTH = 1920;
	const unsigned int SCR_HEIGHT = 1080;

	int RenderManager::startUp() {
	

	if (!glfwInit()) {
		Log(ERROR, "GLFW didnt load");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "generalGameEngine", NULL, NULL);
	if (!window) {
		Log(ERROR, "Window creation failed");
		shutDown();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// load glad

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		Log(ERROR, "Glad did not load");
		shutDown();
		return -1;
	}

	// vsync 0 = off
	glfwSwapInterval(0);
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_ALWAYS); // for future
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	

}

	void RenderManager::shutDown() {

		glfwTerminate();

	}


	void RenderManager::render(std::vector<GameObject> gameobjects) {

		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// rendering

		for (int i = 0; i < gameobjects.size(); i++){

		gameobjects[i].Draw();

		}
		


		glfwSwapBuffers(window);

		glfwPollEvents();


	}

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

