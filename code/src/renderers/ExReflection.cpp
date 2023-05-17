#include "renderers/ExReflection.h"


ExReflection::ExReflection(int width, int height) : Renderer(width, height)
{
	cube = new Cube2();
	objMat = glm::translate(glm::mat4(), glm::vec3(0.5f, 0.0f, -7.5f));
	color = glm::vec4(0.1f, 0.1f, 0.6f, 1.0f);
}

ExReflection::~ExReflection()
{
	delete cube;
}

void ExReflection::render(float dt)
{
	renderScene(dt);
}

void ExReflection::renderScene(float dt)
{
	CubeAttrib cubes[] = {
		CubeAttrib {glm::vec3(0.5f, 0.0f, -7.5f), glm::vec4(0.1f, 0.1f, 0.6f, 1.0f)},
		CubeAttrib {glm::vec3(0.0f, 0.0f, -6.0f), glm::vec4(0.6f, 0.1f, 0.1f, 0.5f)}
	};

	std::map<float, CubeAttrib> sorted;
	for (int i = 0; i < 2; i++)
	{
		float dist = glm::length(glm::vec3(panv[0], panv[1], panv[2]) - cubes[i].pos);
		sorted[dist] = cubes[i];
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_DEPTH_TEST);

	for (std::map<float, CubeAttrib>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); it++)
	{
		CubeAttrib attrib = it->second;
		objMat = glm::translate(glm::mat4(), attrib.pos);
		cube->setColor(attrib.color);
		cube->setTransforms(objMat, cam);
		cube->draw();
	}

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}