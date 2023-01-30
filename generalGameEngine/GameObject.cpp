#include "GameObject.h"
#include <GLFW/glfw3.h>
#include <iostream>







void GameObject::Draw()
{

	// Identity matrix
	glm::mat4 trans = glm::mat4(1.0f);

	model->shader->use();

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
