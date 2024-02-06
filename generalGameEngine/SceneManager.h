#pragma once
#include "Scene.h"


class SceneManager
{

public:
	Scene* scene;

	static SceneManager& get_instance();

private:
	SceneManager();
	static SceneManager* instance;


public:
	void load_scene(std::string const& path);
	void save_scene(std::string const& name);
	void new_scene();





};

