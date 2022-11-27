#pragma once
#include<string>
#include<iostream>
#include"Shader.h"
class Model
{
public:


	Shader* shader;


	Model(std::string const &path) {

		loadModel(path);

	}

	void Draw();


private:

	void loadModel(std::string const& path);
};


