#include "generalGameEngine.h"
#include "logger.h"
#include "Commander.h"
#include "GameObject.h"
#include "TextureLoader.h"
#include <vector>
#include <iostream>
#include <glm/gtx/string_cast.hpp>



Camera* camera = new Camera("test");

// timing
double previous = static_cast<float>(glfwGetTime());
double lag = 0.0f;
const unsigned int MS_PER_UPDATE = 7; // 1000/144 ms/fps
double deltaTime;



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
		deltaTime = current - previous;
		previous = current;
		lag += deltaTime;

		// process input function
		InputManager::processInput(window, *camera, deltaTime);
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

		
		tempfunc();
		gameobjects.push_back(GameObject("Object", "cube", *camera));


}

void update() {


	for (int i = 0; i < gameobjects.size(); i++) {

		gameobjects[i].Update();


	}

}

