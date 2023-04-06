#include "renderers/Light.h"

Light::Light(glm::vec3 color, float strength)
{
	this->color = color;
	ambientStrength = strength;
	ambient = this->color * ambientStrength;
}

Light::~Light()
{

}

glm::vec3 Light::GetColor()
{
	return color;
}

float Light::GetAmbientStrenght()
{
	return ambientStrength;
}

glm::vec3 Light::GetAmbient()
{
	return ambient;
}

glm::vec3 Light::GetAmbientResult()
{
	return result;
}

void Light::SetAmbientResult(glm::vec3 objColor)
{
	result = ambient * objColor;
}