#include "Scene.h"
#include "InputManager.h"

void Scene::init_scene() {

	setCamera(camera);

}




void Scene::new_gameobject(std::string const& name, std::string const& path)
{

	gameobjects.push_back(GameObject(name, path, *camera));


}

void Scene::update_scene()
{

	// Loops through all game objects and updates their status, like position and rotation.
	for (int i = 0; i < gameobjects.size(); i++) {

		gameobjects[i].Update();


	}


}

void Scene::render_scene()
{

	// Passed the vector to the Rendermanager where it will loop and call every objects draw function
	RenderManager::render(gameobjects);

}
