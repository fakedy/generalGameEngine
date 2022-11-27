#pragma once
#include<string>
#include<iostream>
class Model
{
public:
	Model(std::string const &path) {

		loadModel(path);

	}

	void Draw();


private:

	void loadModel(std::string const& path);
};


