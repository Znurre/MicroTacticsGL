#version 330 core

out vec4 result;

in vec3 color;

void main(void)
{
	result = vec4(color, 0);
}
