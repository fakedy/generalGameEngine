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

	unsigned int objectID;
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
	GameObject() = default;
	GameObject(std::string const& name, std::string const& path, glm::vec3 Position, glm::vec3 size,glm::vec3 rotaxis, float rot, Camera& usedcamera) {


		objectName = name;
		position = Position;
		scale = size;
		rotateAxis = rotaxis;
		rotation = rot;
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




