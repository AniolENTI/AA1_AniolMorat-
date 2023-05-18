#pragma once
#include <Program.h>
#include <renderers/Renderer.h>

class TexturePlane : public Renderer
{
public:
	TexturePlane(int width, int height, glm::vec3 topRight, glm::vec3 topLeft, glm::vec3 botLeft, glm::vec3 botRight);
	~TexturePlane();
	void render(float dt) override;
private:
	//Cube* cube;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint texture;
	
	Program* program;
};

