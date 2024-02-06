#pragma once

#include "Mesh.h"
#include "stb_image.h"

#include <assimp/scene.h>


#include <vector>
#include <string>





class Model {
public:

	Model(std::string const& path) {

		loadModel(path);

	}

	void Draw(Shader &shader);


private:

	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;

	void loadModel(std::string const& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	unsigned int TextureFromFile(const char* path, const std::string& directory);

};


