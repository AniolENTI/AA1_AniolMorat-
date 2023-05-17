#include <renderers/ExSimpleFBO.h>

ExSimpleFBO::ExSimpleFBO(int width, int height) : Renderer(width, height)
{
	dragon = new Models::Model("objects/dragon.obj");
	cube = new PhongCube();
	light = new PointLightSource();

	texturePlane = new TexturePlane();

	setupFBO();
}

void ExSimpleFBO::setupFBO() {
	glGenFramebuffers(1, &fbo);

	GLuint rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 800);  // 24 bits for depth, 8 bits for stencil
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glGenTextures(1, &fbo_tex);
	glBindTexture(GL_TEXTURE_2D, fbo_tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2D(
		GL_FRAMEBUFFER,
		GL_COLOR_ATTACHMENT0,  // En quin buffer ho guardem (color, depth, stencil)
		GL_TEXTURE_2D,
		fbo_tex,
		0
	);
	// WARNING: If this part is commented we will not see the dragon. Why?
	// glFramebufferRenderbuffer(
	// 	GL_FRAMEBUFFER,
	// 	GL_DEPTH_STENCIL_ATTACHMENT,
	// 	GL_RENDERBUFFER,
	// 	rbo
	// );
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

ExSimpleFBO::~ExSimpleFBO()
{
	delete dragon;
	delete cube;
	delete light;
	delete texturePlane;
}

void ExSimpleFBO::render(float dt)
{
	// Setup fbo camera
	CameraTransforms fbCam;
	fbCam._modelView = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 3.f));
	fbCam._projection = glm::perspective(FOV, 1.f, zNear, zFar);
	fbCam._MVP = fbCam._projection * fbCam._modelView;

	// RENDER IN THE NEW FRAMEBUFFER
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glViewport(0, 0, 800, 800);
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	drawScene(fbCam);

	// Restore the state
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, width, height);  // Remember to store the width and the height in Renderer

	// Draw the textured plane with the FBO
	// You must refactor the textures example that we did in
	// class into a class that follows this interface
	texturePlane->setTransforms(
		glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -6.f)),
		cam
	);
	texturePlane->setTexture(fbo_tex);
	texturePlane->draw();

	drawScene(cam);
}

void ExSimpleFBO::drawScene(CameraTransforms cam)
{
	// Change the implementation of this function
	// and add whatever scene you want to draw

	// Transform light source
	light->setPosition(glm::vec3(8.f * glm::sin(ImGui::GetTime()), 8.f, -3.f));
	light->setProperties(glm::vec3(1.f, 1.f, 1.f), 1000.f);
	light->setTransforms(cam);

	// Transform the model
	dragon->setTransforms(
		glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -8.f)) *
		glm::scale(glm::mat4(), glm::vec3(.05f)),
		cam
	);
	dragon->setColor(glm::vec4(.8f, .2f, .2f, 1.f));
	dragon->setLight(light);

	// Place the cube
	cube->setTransforms(
		glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -11.f)) *
		glm::scale(glm::mat4(), glm::vec3(8.f, 8.f, .5f)),
		cam
	);
	cube->setColor(glm::vec4(.2f, .2f, .8f, 1.f));
	cube->setLight(light);

	dragon->draw();
	cube->draw();
	light->draw();
}
