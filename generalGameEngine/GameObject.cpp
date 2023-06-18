#include "GameObject.h"
#include "Model.h"
#include <GLFW/glfw3.h>
#include <iostream>



void GameObject::Draw()
{

	shader->use();

	// projection matrix
	glm::mat4 projection;
	projection = camera->projection;
	shader->setMat4("projection", projection);


	// view matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = camera->GetViewMatrix();
	shader->setMat4("view", view);


	// Identity matrix
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, position);
	trans = glm::scale(trans, scale);
	trans = glm::rotate(trans, glm::radians(rotation), rotateAxis);


	shader->setMat4("transform", trans);


	//Model::Draw(Shader & shader)
	model->Draw(*shader);
	shader->setVec3("plyPos",camera->position);


}

void GameObject::Update()
{
	// Why do I still do the matrix calculations every draw when they are static? I should make sure we skip almost everything in draw function. And is there no way I can get rid of the Update function for static objects?
	if (staticObject != true) {

		rotation = rotation;
		position = position;

	}

}
