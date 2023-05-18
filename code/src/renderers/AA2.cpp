#include "renderers/AA2.h"

AA2::AA2(int width, int height) : Renderer(width, height)
{
	//PROVA TEXTURA
	glm::vec3 topRight = { 0.5f, 0.5f, 0.0f };
	glm::vec3 topLeft = { -0.5f, 0.5f, 0.0f };
	glm::vec3 botLeft = { -0.5f, -0.5f, 0.0f };
	glm::vec3 botRight = { 0.5f, -0.5f, 0.0f };
	filepath = "textures/container.jpg";
	TexturePlane* temp = new TexturePlane(width, height, topRight, topLeft, botLeft, botRight, filepath);
	textures.push_back(temp);
}

AA2::~AA2()
{
	delete cub;
	for (int i = 0; i < textures.size(); i++)
		delete textures[i];
}

void AA2::render(float dt)
{
	for (int i = 0; i < textures.size(); i++)
		textures[i]->render(dt);
}