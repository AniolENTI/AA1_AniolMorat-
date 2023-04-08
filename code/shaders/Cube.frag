#version 330

in vec4 vert_Normal;
out vec4 out_Color;

uniform mat4 mv_Mat;
uniform vec4 color;
uniform vec4 light_Color;

in vec3 frag_Position;

void main() {
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * light_Color;

	vec4 result = ambient * color;

	out_Color = vec4(result, 1.0);
}