#version 330 core

uniform mat4 M;
uniform mat4 VP;

uniform vec3 primaryColor;
uniform vec3 secondaryColor;

in vec3 vertex;
in vec3 normal;

out vec3 color;

void main()
{
	gl_Position = VP * M * vec4(vertex.xyz, 1);

	if (normal.y > 0 || normal.x > 0)
	{
		color = secondaryColor;
	}
	else
	{
		color = primaryColor;
	}
}
