#version 330

in vec4 vert_Normal;
in vec3 frag_Position;

uniform mat4 mv_Mat;
uniform vec4 color;

out vec4 out_Color;

void main() {
	out_Color = color;
}