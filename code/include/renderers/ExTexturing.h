#pragma once
#include "Renderer.h"
//#include <objects/Cube.h>
#include <Program.h>

class ExTexturing : public Renderer
{
public:
	ExTexturing(int width, int height);
	~ExTexturing();
protected:
	void render(float dt);
private:
	//Cube* cube;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint texture;

	Program* program;
};

