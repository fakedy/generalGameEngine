
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;



void main()
{

    // Will attempt to disable subpixel rasterization
    vec2 grid = vec2(384, 216)/2;

    vec4 vertex = view * transform * vec4(aPos, 1.0);

    vec4 clipspace = view * transform * vec4(aPos, 1.0);
    clipspace.xyz = vertex.xyz / vertex.w; // convert to normalised device coordinates (NDC)
    clipspace.xy = floor(grid * clipspace.xy) / grid; // snap the vertex to the lower-resolution grid
    // clipspace.xyz *= vertex.w; // convert back to projection-space

    


    gl_Position = projection * clipspace;
    fragPos = vec3(transform * vec4(aPos, 1.0));




    texCoord = aTexCoord;
    normal = mat3(transpose(inverse(transform))) * aNormal;
}