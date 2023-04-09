#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Cube.h>

class AA1 : public Renderer
{
public:
	AA1(int width, int height);
	~AA1();
protected:
	void render(float dt);
	void renderGUI(float dt);
private:
	Cube* cube;
	glm::mat4 objMat;
	glm::vec4 cubeColor, lightColor;
	glm::vec3 lightPosition;

	const float MAX_POSITION = 25;
	const float MIN_POSITION = -25;

	const float MAX_COLOR = 1.0f;
	const float MIN_COLOR = 0.0f;

	const float MAX_STRENGTH = 1.0f;
	const float MIN_STRENGTH = 0.0f;

	bool canEditPosition, canEditColor, canEditStrength, canEditCubeColor;

	float ambientStrength, specularStrength;
};
