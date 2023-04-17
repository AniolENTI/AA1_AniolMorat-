#include "renderers/ExNormal.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

ExNormal::ExNormal(int width, int height) : Renderer(width, height)
{
	cube = new Cube2();
	objMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	cubeColor = { 1.0f, 0.3f, 0.6f, 1.0f };
	canEditCubeColor = false;
}

ExNormal::~ExNormal()
{
	delete cube;
}

void ExNormal::render(float dt)
{
	cube->setColor(cubeColor);
	cube->setTransforms(objMat, cam);
	cube->draw();
	renderGUI(dt);
}

void ExNormal::renderGUI(float dt)
{
	ImGui::Checkbox("Color Cub", &canEditCubeColor);
	ImGui::Spacing();
	if (canEditCubeColor)
	{
		ImGui::Text("COLOR CUB");
		ImGui::SliderFloat("Vermell",
			&cubeColor.r,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::SliderFloat("Verd",
			&cubeColor.g,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::SliderFloat("Blau",
			&cubeColor.b,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::Spacing();
	}
}