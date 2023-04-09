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
private:
	Cube* cube;
	glm::mat4 objMat;
	glm::vec4 cubeColor, lightColor;
	glm::vec3 lightPosition;
};
