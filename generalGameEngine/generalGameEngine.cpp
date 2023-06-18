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
		return 0;
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

		// We have to add the camera we're using but it seem kinda weird way of doing it.
		// Creates a new gameobject and adds it to a vector so we can keep track of all gameobjects.
		gameobjects.push_back(GameObject("tree", "models/characters/snake_shirtless/solid_snake_shirtless.obj", *camera));
		gameobjects[0].position = glm::vec3(5.0, 2.3, 3.0);
		gameobjects[0].scale = glm::vec3(0.2, 0.2, 0.2);
		gameobjects.push_back(GameObject("vysage", "models/locations/autumn_plains/autumn_plains.obj", *camera));
		gameobjects[1].position = glm::vec3(-60.0, -15, 70.0);
		gameobjects[1].scale = glm::vec3(0.01, 0.01, 0.01);
		gameobjects[1].rotateAxis = glm::vec3(1, 0, 0);
		gameobjects[1].rotation = -90.f;






}

void update() {

	// Loops through all game objects and updates their status, like position and rotation.
	for (int i = 0; i < gameobjects.size(); i++) {

		gameobjects[i].Update();


	}

}

