#pragma once


#include "GameObject.h"
#include "Commander.h"
#include "Camera.h"
#include <vector>
#include <unordered_map>




class Scene
{


public:

	Camera* camera;

	Scene() : camera(new Camera("test")) {
		
		init_scene();

	}


	//std::vector<GameObject> gameobjects; // A vector containing all the gameobjects
	std::unordered_map<unsigned int, GameObject> gameobjects;



	~Scene() {

		delete camera;
	}


public:

	std::string const& name = "defaultscene";


	void init_scene();
	void new_gameobject(std::string const& name = "gameobject", std::string const& path = "models/default/errorcube.obj", glm::vec3 position = glm::vec3(0.0, 0.0, 0.0), glm::vec3 size = glm::vec3(1.0, 1.0, 1.0), glm::vec3 rotaxis = glm::vec3(1.0, 1.0, 1.0), float rotation = 0.0, std::string const& vShader = "shaders/vsDefaultShader.glsl", std::string const& fShader = "shaders/fsDefaultShader.glsl");

	void update_scene();

	void render_scene();

};



// The plan is to have this manage everything that is going on in a certain scene. Maybe i could add savable scenes and load them in here.