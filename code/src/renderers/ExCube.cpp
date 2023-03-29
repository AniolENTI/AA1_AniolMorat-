#include "renderers/ExCube.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

ExCube::ExCube(int width, int height) : Renderer(width, height)
{
	cube = new Cube();
}

ExCube::~ExCube()
{
	delete cube;
}

void ExCube::render(float dt)
{
	cube->setColor();
	cube->setTransforms();
	cube->draw();
}