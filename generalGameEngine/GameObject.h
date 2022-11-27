#pragma once
#include<glm/glm.hpp>
#include"Model.h"

class GameObject
{
public:


	std::string objectName = "gameobject";
	glm::fvec3 position = glm::fvec3(0,0,0);
	glm::fvec3 rotation;

	std::string modelPath = "triangle"; 



	GameObject(std::string const& name, std::string const& path) {

		objectName = name;
		modelPath = path;

		loadModel(modelPath);

	}



};


