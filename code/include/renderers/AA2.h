#pragma once
#include <objects/Cube2.h>
#include <renderers/Renderer.h>
#include <objects/TexturePlane.h>
#include <vector>

class AA2 : public Renderer
{
public:
	AA2(int width, int height);
	~AA2();
	void render(float dt) override;
private:
	Cube2* cub;
	std::vector<TexturePlane>textures;
};

