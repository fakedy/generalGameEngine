#include "GameObject.h"
#include "Camera.h"
#include <GLFW/glfw3.h>
#include <iostream>



void GameObject::Draw()
{

	model->shader->use();

	// projection matrix
	glm::mat4 projection;
	projection = camera->projection;
	model->shader->setMat4("projection", projection);


	// view matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = camera->GetViewMatrix();
	model->shader->setMat4("view", view);

	// Identity matrix
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, position);
	trans = glm::rotate(trans, rotation, glm::vec3(1.0f, 1.0f, 1.0f));

	model->shader->setMat4("transform", trans);


	model->Draw();

}

void GameObject::Update()
{
	if (staticObject != true) {

		rotation = (float)glfwGetTime();
		position = position;


	}

}
