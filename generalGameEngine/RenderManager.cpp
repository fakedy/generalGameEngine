#include "RenderManager.h"
#include "logger.h"


	GLFWwindow* window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	int RenderManager::startUp() {
	

	if (!glfwInit()) {
		Log(ERROR, "GLFW didnt load");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	window = glfwCreateWindow(1920, 1080, "generalGameEngine", NULL, NULL);
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

}

	void RenderManager::shutDown() {

		glfwTerminate();

	}


	void RenderManager::render() {

		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// rendering






		glDrawArrays(GL_LINES, 0,36);


		glfwSwapBuffers(window);

		glfwPollEvents();


	}

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}