#pragma once
#include <objects/Cube2.h>
#include <renderers/Renderer.h>
#include <map>

class ExReflection : public Renderer
{
public:
	ExReflection(int width, int height);
	~ExReflection();
	void render(float dt) override;

private:
	Cube2* cube;
	glm::mat4 objMat;
	glm::vec4 color;

	void renderScene(float dt);
};

struct CubeAttrib
{
	glm::vec3 pos;
	glm::vec4 color;
};
