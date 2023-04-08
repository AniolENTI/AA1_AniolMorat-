#include "renderers/Light.h"

#pragma region General
Light::Light(glm::vec3 color, float strength, glm::vec3 pos, glm::vec3 normal, glm::vec3 fragPos)
{
	this->color = color;
	ambientStrength = strength;
	ambient = this->color * ambientStrength;

	lightPosition = pos;

	norm = glm::normalize(normal);
	lightDirection = glm::normalize(lightPosition - fragPos);

	diffuseStrength = glm::max(glm::dot(norm, lightDirection), 0.0f);
	diffuse = diffuseStrength * this->color;
}

Light::~Light()
{

}

glm::vec3 Light::GetColor()
{
	return color;
}

glm::vec3 Light::GetResult()
{
	return result;
}

void Light::SetResult(glm::vec3 objColor)
{
	result = (ambient + diffuse) * objColor;
}
#pragma endregion

#pragma region Ambient
float Light::GetAmbientStrenght()
{
	return ambientStrength;
}

glm::vec3 Light::GetAmbient()
{
	return ambient;
}
#pragma endregion

#pragma region Diffuse
glm::vec3 Light::GetLightPos()
{
	return lightPosition;
}

void Light::SetLightPos(glm::vec3 pos)
{
	lightPosition = pos;
}
#pragma endregion

