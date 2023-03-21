#include "Model.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "primitives.h"
#include "logger.h"
#include <iostream>
#include <vector>

    unsigned int VBO, VAO;



    

void Model::loadModel(std::string const &path) {

	std::cout << "Loading: " << path << std::endl;

    // Not intended to be hardcoded like this but it is what it is.
	if (path == "cube") {


        shader = new Shader("vsDefaultShader.glsl", "fsDefaultShader.glsl");
        shader->use();
        

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(primitives::cube::vertices), primitives::cube::vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

            
        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);



    }
    else {

        Log(ERROR, "Invalid Path to object");

    }


}


void Model::Draw() {

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(primitives::cube::vertices)/sizeof(float));
    glBindVertexArray(0);

}
