#pragma once
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Model.h"
#include"Shader.h"
#include"logger.h"
#include"Camera.h"
#include<iostream>

class GameObject
{
public:


	std::string objectName = "gameobject";
	glm::vec3 position = glm::fvec3(0,0,0);
	glm::vec3 scale = glm::fvec3(1.0, 1.0, 1.0);
	glm::vec3 rotateAxis = glm::fvec3(0.0, 1.0, 0.0);
	float rotation = 0.0f;
	bool staticObject = false;
	std::string modelPath;
	Model* model;

	Shader* shader;
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
			// doesnt this technically mean I create a new shader for every single object instead of reusing the same one?
			shader = new Shader("shaders/vsDefaultShader.glsl", "shaders/fsDefaultShader.glsl");

	}

	void Draw();

	void Update();
	
};




