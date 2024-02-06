#include "generalGameEngine.h"
#include "logger.h"
#include "Commander.h"
#include "SceneManager.h"
#include <vector>
#include <iostream>
#include <glm/gtx/string_cast.hpp>


// timing
double previous = static_cast<float>(glfwGetTime());
double lag = 0.0f;
const unsigned int MS_PER_UPDATE = 7; // 1000/144 ms/fps
double deltaTime;

SceneManager scenemanager = SceneManager::get_instance();

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
		// need to fix this not needing the camera referenced
		InputManager::processInput(window, deltaTime);

		update();

		while (lag >= MS_PER_UPDATE) {

			update();
			lag -= MS_PER_UPDATE;

		}

		scenemanager.scene->render_scene();

		
		
	}

	glfwTerminate();
	
	return 0;

}

void start() {


		// Loads a scene file from disk.
		scenemanager.load_scene("scenes/autumn_valley.scene");

		// Loads model files as stores them as gameobjects in an unordered map
		scenemanager.scene->new_gameobject("castle", "models/locations/autumn_plains/autumn_plains.obj", glm::vec3(-60.0, -15.0, 70.0), glm::vec3(0.01, 0.01, 0.01), glm::vec3(1, 0, 0), -90.0);
		scenemanager.scene->new_gameobject("spyro", "models/characters/spyro/spyro.obj", glm::vec3(0.0, 5.0, 30.0));
		scenemanager.scene->new_gameobject("scenery", "models/skybox/Ashleys_Flashback/Ashley_flashback_no_tree.obj", glm::vec3(0.0, -16.0, -15.0), glm::vec3(3.5, 3.5, 3.5));


		scenemanager.save_scene("autumn_valley.scene");
}

void update() {

	scenemanager.scene->update_scene();


}

