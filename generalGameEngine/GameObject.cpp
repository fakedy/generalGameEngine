#include "GameObject.h"
#include <iostream>







void GameObject::Draw()
{

	// Identity matrix
	glm::mat4 trans = glm::mat4(1.0f);

	model->shader->use();

	trans = glm::translate(trans, position);

	model->shader->setMat4("transform", trans);

	model->Draw();


}

void GameObject::Update()
{
	if (staticObject != true) {

		


	}

}
