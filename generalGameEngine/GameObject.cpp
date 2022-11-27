#include "GameObject.h"
#include <iostream>


void GameObject::Draw()
{

	model->Draw();


}

void GameObject::Update()
{
	model->shader->use();
		

}
