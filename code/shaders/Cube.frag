#version 330

in vec4 vert_Normal;
in vec3 frag_Position;

uniform mat4 mv_Mat;
uniform vec4 color;
uniform vec4 light_Color;
uniform vec3 light_Position;
uniform vec3 camera_Position;

out vec4 out_Color;

void main() {
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * light_Color;

	vec4 norm = normalize(vert_Normal);
	vec4 light_Direction = vec4(normalize(light_Position - frag_Position), 0.0);
	float diff = max(dot(norm, light_Direction), 0.0);
	vec4 diffuse = diff * light_Color;

	float specularStrength = 0.5;
	vec4 camera_Direction = vec4(normalize(camera_Position - frag_Position), 0.0);
	vec4 reflection_Direction = reflect(-light_Direction, norm);
	float spec = pow(max(dot(camera_Direction, reflection_Direction), 0.0), 32);
	vec4 specular = specularStrength * spec * light_Color;

	vec4 result = (ambient + diffuse + specular) * color;
	out_Color = result;
}