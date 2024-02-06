#version 330 core
out vec4 FragColor;

in vec2 texCoord;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D texture_diffuse1;


uniform vec3 plyPos;


vec3 lightPos = vec3(15.0, 50.0, 3.0);


float fragDist = pow((pow((plyPos.x - fragPos.x), 2) + pow((plyPos.y - fragPos.y), 2) + pow((plyPos.z - fragPos.z), 2)), 0.5); // calculates distance between camera and frag position. seems like glsl already have a dist func lol.



vec3 lightColor = vec3(0.8);

vec3 norm = normalize(normal);
vec3 lightDir = normalize(lightPos - fragPos);

float diff = max(dot(norm, lightDir), 0.0);


float ambientStrength = 0.4;

vec3 ambient = ambientStrength * lightColor;
vec3 diffuse = diff * lightColor;


float get_fog_factor() {

	float nearplane = 190.0; // Where the fog starts
	float farplane = 200.0; // where the max fog is reached

	float fogmax = 1.0 * farplane;
	float fogmin = 0.5 * farplane;
	if (fragDist >= fogmax)discard; // fog edge
	if (fragDist <= fogmin)return 0.0; // fog edge


	return 1.0 - (fogmax - fragDist) / (fogmax - fogmin); // everything between the fog edges
}

void main()
{
	float fogFactor = get_fog_factor();

	vec4 texColor = texture(texture_diffuse1, texCoord) * vec4(ambient + diffuse, 1.0);
	if (texColor.a < 0.1)
		discard;


	FragColor = mix(texColor, vec4(vec3(247/255, 187/255, 96/255), 0.0), fogFactor); // fogfactor is the blend value aka the fog

}