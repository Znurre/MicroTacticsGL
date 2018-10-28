#version 330 core

uniform mat4 M;
uniform mat4 VP;

in vec3 vertex;

void main()
{
	gl_Position = VP * M * vec4(vertex.xyz, 1);
}
