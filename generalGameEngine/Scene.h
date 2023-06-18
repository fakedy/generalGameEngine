#pragma once


#include "GameObject.h"
#include "Commander.h"
#include "Camera.h"
#include <vector>




class Scene
{


public:

	Camera* camera;

	Scene() : camera(new Camera("test")) {
		
		init_scene();

	}


	std::vector<GameObject> gameobjects; // A vector containing all the gameobjects

	~Scene() {

		delete camera;
	}


public:

	


	void init_scene();
	void new_gameobject(std::string const& name, std::string const& path);

	void update_scene();

	void render_scene();

};



// The plan is to have this manage everything that is going on in a certain scene. Maybe i could add savable scenes and load them in here.