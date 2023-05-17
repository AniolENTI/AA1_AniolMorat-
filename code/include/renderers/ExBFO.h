#pragma once
#include "Renderer.h"
#include <objects/PhongCube.h>
#include <objects/Models.h>
#include <objects/PointLightSource.h>
#include <objects/TexturePlane.h>

class ExSimpleFBO :
    public Renderer
{
    Models::Model* dragon;
    PhongCube* cube;
    PointLightSource* light;
    TexturePlane* texturePlane;

    GLuint fbo, fbo_tex;

public:
    ExSimpleFBO(int width, int height);
    ~ExSimpleFBO();
protected:
    void render(float dt) override;
private:
    void setupFBO();
    void drawScene(CameraTransforms cam);
};