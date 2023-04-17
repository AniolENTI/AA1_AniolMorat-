#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Cube2.h>

class ExNormal : public Renderer
{
public:
	ExNormal(int width, int height);
	~ExNormal();
protected:
	void render(float dt);
	void renderGUI(float dt);
private:
	Cube2* cube;
	glm::mat4 objMat;
	glm::vec4 cubeColor;

	const float MAX_COLOR = 1.0f;
	const float MIN_COLOR = 0.0f;

	bool  canEditCubeColor;
};