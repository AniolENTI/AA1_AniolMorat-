#include "renderers/AA1.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

AA1::AA1(int width, int height) : Renderer(width, height)
{
	cube = new Cube();
	objMat = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -10.0f));
	cubeColor = { 1.0f, 0.3f, 0.6f, 1.0f };
	lightColor = { 0.7f, 0.4f, 0.2f, 1.0f };
	lightPosition = { 1.0f, 1.0f, -8.0f };
	ambientStrength = 0.1f;
	specularStrength = 0.5f;

	canEditPosition = false;
	canEditColor = false;
	canEditStrength = false;
	canEditCubeColor = false;
}

AA1::~AA1()
{
	delete cube;
}

void AA1::render(float dt)
{
	cube->setColor(cubeColor);
	cube->setLightColor(lightColor);
	cube->setLightPosition(lightPosition);
	cube->setLightStrength(ambientStrength, specularStrength);
	cube->setTransforms(objMat, cam);
	cube->draw();
	renderGUI(dt);
}

void AA1::renderGUI(float dt)
{
	ImGui::Checkbox("Posicio", &canEditPosition);
	ImGui::Spacing();
	if (canEditPosition)
	{
		ImGui::Text("POSICIO LLUM");
		ImGui::SliderFloat("Posicio X",
			&lightPosition.x,
			MIN_POSITION,
			MAX_POSITION);
		ImGui::SliderFloat("Posicio Y",
			&lightPosition.y,
			MIN_POSITION,
			MAX_POSITION);
		ImGui::SliderFloat("Posicio Z",
			&lightPosition.z,
			MIN_POSITION,
			MAX_POSITION);
		ImGui::Spacing();
	}
	
	ImGui::Checkbox("Color", &canEditColor);
	ImGui::Spacing();
	if (canEditColor)
	{
		ImGui::Text("COLOR LLUM");
		ImGui::SliderFloat("Vermell",
			&lightColor.r,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::SliderFloat("Verd",
			&lightColor.g,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::SliderFloat("Blau",
			&lightColor.b,
			MIN_COLOR,
			MAX_COLOR);
		ImGui::Spacing();
	}
	
	ImGui::Checkbox("Forca", &canEditStrength);
	ImGui::Spacing();
	if (canEditStrength)
	{
		ImGui::Text("FORCES DE LA LLUM");
		ImGui::SliderFloat("Ambiental",
			&ambientStrength,
			MIN_STRENGTH,
			MAX_STRENGTH);
		ImGui::SliderFloat("Especular",
			&specularStrength,
			MIN_STRENGTH,
			MAX_STRENGTH);
		ImGui::Spacing();
	}

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