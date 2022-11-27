#include "logger.h"
#include "Commander.h"
#include "GameObject.h"
#include <vector>


// timing
double previous = static_cast<float>(glfwGetTime());
double lag = 0.0f;
const unsigned int MS_PER_UPDATE = 7; // 1000/144 ms/fps


std::vector<GameObject> gameobjects; // A vector containing all the gameobjects

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

		// not sure the updating is correct

		// deltaTime
		double current = static_cast<float>(glfwGetTime());
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		// process input function
		InputManager::processInput(window);
		update();

		while (lag >= MS_PER_UPDATE) {

			update();
			lag -= MS_PER_UPDATE;

		}


		RenderManager::render(gameobjects);
		
	}

	glfwTerminate();
	
	return 0;

}

void start() {
	
	gameobjects.push_back(GameObject("Object", "cube"));

	
}

void update() {


	for (int i = 0; i < gameobjects.size(); i++) {

		gameobjects[i].Update();

	}

}

