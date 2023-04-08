#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Cube.h>
#include <renderers/Light.h>

class AA1 : public Renderer
{
public:
	AA1(int width, int height);
	~AA1();
protected:
	void render(float dt);
private:
	Cube* cube;
	Light* light;
	glm::mat4 objMat;
	glm::vec4 color;
	glm::vec3 lightColor;
	glm::vec3 lightPos;
};
