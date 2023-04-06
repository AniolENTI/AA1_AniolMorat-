#pragma once
#include "Renderer.h"

class Light
{
private:
	//GENERAL VALUES
	glm::vec3 color;
	const float MIN_RGB_VALUE = 0.0f;
	const float MAX_RGB_VALUE = 1.0f;

	//AMBIENT LIGHT
	float ambientStrength;
	glm::vec3 ambient;
	glm::vec3 result;
	const float MIN_A_STRENGTH = 0.0f;
	const float MAX_A_STRENGTH = 1.0f;
public:
	//GENERAL FUNCTIONS
	Light(glm::vec3 color, float strength);
	~Light();
	glm::vec3 GetColor();

	//AMBIENT FUNCTIONS
	float GetAmbientStrenght();
	glm::vec3 GetAmbient();
	glm::vec3 GetAmbientResult();
	void SetAmbientResult(glm::vec3 objColor);
};