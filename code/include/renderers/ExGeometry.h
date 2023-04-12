#pragma once
#include "Renderer.h"
#include <Program.h>

class ExGeometry :
    public Renderer
{
    Program* program;
    GLuint VAO;
    GLuint VBO;

public:
    ExGeometry(int width, int height);
    ~ExGeometry();
protected:
    void render(float dt);
};