#pragma once
#include <objects/Cube2.h>
#include <renderers/Renderer.h>
#include <map>

class ExTransparency : public Renderer
{
public:
	ExTransparency(int width, int height);
	~ExTransparency();
	void render(float dt) override;

private:
	Cube2* cube;
	glm::mat4 objMat;
	glm::vec4 color;
};

struct CubeAttrib
{
	glm::vec3 pos;
	glm::vec4 color;
};
