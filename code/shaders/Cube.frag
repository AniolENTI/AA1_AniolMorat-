#version 330

in vec4 vert_Normal;
in vec3 frag_Position;

uniform mat4 mv_Mat;
uniform vec4 color;
uniform vec4 light_Color;
uniform vec3 light_Position;

out vec4 out_Color;

void main() {
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * light_Color;

	vec4 norm = normalize(vert_Normal);
	vec4 light_Direction = vec4(normalize(light_Position - frag_Position), 0.0);
	float diff = max(dot(norm, light_Direction), 0.0);
	vec4 diffuse = diff * light_Color;

	vec4 result = (ambient + diffuse) * color;
	out_Color = result;
}