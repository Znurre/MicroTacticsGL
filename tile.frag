#version 330 core

out vec4 result;

uniform float color;

void main(void)
{
	result = vec4(1, color, 0, 0);
}
