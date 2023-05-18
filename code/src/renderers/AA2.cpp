#include "renderers/AA2.h"

AA2::AA2(int width, int height) : Renderer(width, height)
{

}

AA2::~AA2()
{
	delete cub;
}

void AA2::render(float dt)
{

}