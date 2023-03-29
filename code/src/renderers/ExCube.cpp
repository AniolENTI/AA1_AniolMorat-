#include "renderers/ExCube.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

ExCube::ExCube(int width, int height) : Renderer(width, height)
{
	cube = new Cube();
	objMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	color = { 1.0f, 0.3f, 0.6f, 1.0f };
}

ExCube::~ExCube()
{
	delete cube;
}

void ExCube::render(float dt)
{
	cube->setColor(color);
	cube->setTransforms(objMat, cam);
	cube->draw();
}