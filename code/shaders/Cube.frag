#version 330

in vec4 vert_Normal;
out vec4 out_Color;

uniform mat4 mv_Mat;
uniform vec4 color;

in vec3 frag_Position;

void main() {
	out_Color = color;
}