#pragma once
#include "Renderer.h"
#include <Program.h>
#include <objects/Cube.h>

class ExCube : public Renderer
{
public:
	ExCube(int width, int height);
	~ExCube();
protected:
	void render(float dt);
private:
	Cube* cube;
	glm::mat4 objMat;
	glm::vec4 color;
};
