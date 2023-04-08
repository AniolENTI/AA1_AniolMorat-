#include "renderers/AA1.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

AA1::AA1(int width, int height) : Renderer(width, height)
{
	cube = new Cube();
	objMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	cubeColor = { 1.0f, 0.3f, 0.6f, 1.0f };
	lightColor = { 0.7f, 0.4f, 0.2f, 1.0f };
}

AA1::~AA1()
{
	delete cube;
}

void AA1::render(float dt)
{
	cube->setColor(cubeColor);
	cube->setLightColor(lightColor);
	cube->setTransforms(objMat, cam);
	cube->draw();
}