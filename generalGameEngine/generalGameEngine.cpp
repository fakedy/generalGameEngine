#include "logger.h"
#include "Commander.h"
#include "GameObject.h"
#include <vector>


// timing
double previous = 0.0f;
double lag = 0.0f;
float deltaTime = 0.0f;	// time between current frame and last frame
const unsigned int MS_PER_UPDATE = 7; // 1000/144 ms/fps

void start();
void update();


int main(){
	
	// inits the subsystems
	if (!Commander::init()) {
		Log(ERROR, "SubSystems didnt load properly");
		return -1;
	}




	start();




	
	// engine loop

	while (!glfwWindowShouldClose(window)) {

		// deltaTime
		double current = static_cast<float>(glfwGetTime());
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		deltaTime = elapsed;

		// process input function
		InputManager::processInput(window);

		while (lag >= MS_PER_UPDATE) {

			update();
			lag -= MS_PER_UPDATE;

		}


		RenderManager::render();
	}

	glfwTerminate();
	
	return 0;

}

void start() {


	std::vector<GameObject> gameobjects;

	gameobjects.push_back(GameObject("Object", "triangle"));
	gameobjects.push_back(GameObject("Object", "triangle"));





}

void update() {

	Log(INFO, "hello:)");

}

