#include "SceneManager.h"


SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager() {
	
	scene = new Scene();
}

void SceneManager::load_scene(std::string const& path)
{

}

void SceneManager::save_scene(std::string const& name)
{

	std::ofstream sceneFile;

	sceneFile.open("scenes/" + name);
	for (int i = 0; i < scene->gameobjects.size(); i++) {

		sceneFile << "test\n";
	}

	sceneFile.close();
}

void SceneManager::new_scene()
{
	// Yeah this is nowhere near working. I think there is a lot of stuff i dont delete properly.
	scene = new Scene();
	scene->init_scene();

}


SceneManager& SceneManager::get_instance() {

	if (instance == nullptr) {
		instance = new SceneManager();
	}
	return *instance;
}
