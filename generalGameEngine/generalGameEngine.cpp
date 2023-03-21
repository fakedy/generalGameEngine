#include "generalGameEngine.h"
#include "logger.h"
#include "Commander.h"
#include "GameObject.h"
#include <vector>
#include <iostream>
#include <glm/gtx/string_cast.hpp>


// Creates a camera
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

		// Passed the vector to the Rendermanager where it will loop and call every objects draw function
		RenderManager::render(gameobjects);
		
	}

	glfwTerminate();
	
	return 0;

}

void start() {


		// Creates a new gameobject and adds it to a vector so we can keep track of all gameobjects.
		gameobjects.push_back(GameObject("backpack", "models/backpack2/backpack2.obj", *camera));


}

void update() {

	// Loops through all game objects and updates their status, like position and rotation.
	for (int i = 0; i < gameobjects.size(); i++) {

		gameobjects[i].Update();


	}

}

