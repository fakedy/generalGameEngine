#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Model.h"
#include<iostream>

class GameObject
{
public:


	std::string objectName = "gameobject";
	glm::fvec3 position = glm::fvec3(0,0,0);
	float rotation;
	bool staticObject = false;
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




