#include "generalGameEngine.h"
#include "logger.h"
#include "Commander.h"
#include "GameObject.h"
#include "Scene.h"
#include <vector>
#include <iostream>
#include <glm/gtx/string_cast.hpp>
#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"
Scene *scene;

// timing
double previous = static_cast<float>(glfwGetTime());
double lag = 0.0f;
const unsigned int MS_PER_UPDATE = 7; // 1000/144 ms/fps
double deltaTime;


void start();
void update();


int main(){
	
	scene = new Scene(); 


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

		scene->render_scene();
		
	}

	glfwTerminate();
	
	return 0;

}

void start() {


		// This has to be made proper
		// 
		// 
		// 
		// Creates a new gameobject and adds it to a vector so we can keep track of all gameobjects.

		scene->new_gameobject("snake", "models/characters/snake_shirtless/solid_snake_shirtless.obj");
		scene->new_gameobject("location", "models/locations/autumn_plains/autumn_plains.obj", glm::vec3(-60.0, -15.0, 70.0), glm::vec3(0.01, 0.01, 0.01), glm::vec3(1, 0, 0), -90.0);





}

void update() {

	scene->update_scene();


}

