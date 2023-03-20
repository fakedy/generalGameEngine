#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Model.h"
#include"Camera.h"
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

	Camera* camera;




private:
	
	int shaderID;


public:
	GameObject(std::string const& name, std::string const& path, Camera& usedcamera) {

		objectName = name;
		modelPath = path;
		camera = &usedcamera;

		if (&modelPath != NULL)

			model = new Model(modelPath);
	}

	void Draw();

	void Update();
	
};




