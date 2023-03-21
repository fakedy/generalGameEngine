#pragma once
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>



struct Vertex {

	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangent;


};

struct Texture {

	unsigned int id;
	std::string type;
	std::string path;

};




class Mesh {
public:

	unsigned int VBO, VAO, EBO;

	// Mesh data
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	// Mesh constructor
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures) {

		this->vertices = vertices;
		this->indices = indices;
		this->textures = textures;

		setupMesh();


	}


	void Draw(Shader& shader);
	void setupMesh();
};