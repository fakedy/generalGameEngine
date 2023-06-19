#include "Scene.h"
#include "InputManager.h"

#include<fstream>


void Scene::load_scene(std::string const& path)
{
}

void Scene::save_scene(std::string const& name)
{

	std::ofstream sceneFile;
	
	sceneFile.open("scenes/" + name);
	for (int i = 0; i < gameobjects.size(); i++) {

		sceneFile << "test\n";
	}

	sceneFile.close();
}

void Scene::init_scene() {

	setCamera(camera);

}

// temporary ID for our gameobjects
unsigned int temp = 0;

void Scene::new_gameobject(std::string const& name, std::string const& path, glm::vec3 position, glm::vec3 size, glm::vec3 rotaxis, float rot, std::string const& vShader, std::string const& fShader)
{

	//gameobjects.push_back(GameObject(name, path, *camera));
	gameobjects.emplace(temp, GameObject(name, path, position, size, rotaxis, rot, vShader, fShader, *camera));
	temp += 1;

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
