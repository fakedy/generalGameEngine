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

	std::string fragmentShader = "shaders/fsDefaultShader.glsl";
	std::string vertexShader = "shaders/vsDefaultShader.glsl";

	Camera* camera;




private:
	
	int shaderID;


public:
	GameObject() = default;
	GameObject(std::string const& name, std::string const& path, glm::vec3 Position, glm::vec3 size,glm::vec3 rotaxis, float rot, std::string const& vShader, std::string const& fShader, Camera& usedcamera) {


		objectName = name;
		position = Position;
		scale = size;
		rotateAxis = rotaxis;
		rotation = rot;
		modelPath = path;
		vertexShader = vShader;
		fragmentShader = fShader;
		camera = &usedcamera;

		if (&modelPath != NULL)

			model = new Model(modelPath);
			// doesnt this technically mean I create a new shader for every single object instead of reusing the same one?
			shader = new Shader(vertexShader.c_str(), fragmentShader.c_str());

	}

	void Draw();

	void Update();
	
};




