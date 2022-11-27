#pragma once
#include<glm/glm.hpp>
#include"Model.h"
#include<iostream>

class GameObject
{
public:


	std::string objectName = "gameobject";
	glm::fvec3 position = glm::fvec3(0,0,0);
	glm::fvec3 rotation;

	std::string modelPath; 
	Model* model;


private:
	
	int shaderID;


public:
	GameObject(std::string const& name, std::string const& path) {

		objectName = name;
		modelPath = path;

		if (&modelPath != NULL)

			model = new Model(modelPath);

			
			
	}

	void Draw();

	void Update();
	


};




