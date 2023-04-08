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

	//DIFFUSE LIGHT
	float diffuseStrength;
	glm::vec3 diffuse;
	glm::vec3 lightPosition;
	glm::vec3 norm;
	glm::vec3 lightDirection;

public:
	//GENERAL FUNCTIONS
	Light(glm::vec3 color, float strength, glm::vec3 pos, glm::vec3 normal, glm::vec3 fragPos);
	~Light();
	glm::vec3 GetColor();
	glm::vec3 GetResult();
	void SetResult(glm::vec3 objColor);

	//AMBIENT FUNCTIONS
	float GetAmbientStrenght();
	glm::vec3 GetAmbient();

	//DIFFUSE FUNCTIONS
	float GetDiffuseStrength();
	glm::vec3 GetDiffuse();
	glm::vec3 GetLightPos();
	void SetLightPos(glm::vec3 pos);
};