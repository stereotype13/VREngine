#include "OpenGLApp.h"
#include "..\Graphics\Rectangle.h"
#include "..\Math\vec4.h"

namespace VR { namespace core {

OpenGLApp::OpenGLApp(String title) : mTitle{title} {

		
	
	if (!glfwInit()) {
		//Handle error
	}

	mWindow = glfwCreateWindow(640, 480, mTitle.c_str(), NULL, NULL);
	if (!mWindow) {
		glfwTerminate();
		//Handle Error
	}

	glfwMakeContextCurrent(mWindow);

	//make it so we're not limited to 60 frames per second
	glfwSwapInterval(0);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	
}

void OpenGLApp::Run() {
	//Create one rectangle
	
	
	while (!glfwWindowShouldClose(mWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);
		mRenderer->Begin();
		//VR::core::Rectangle* rectangle = new Rectangle(0.5f, 0.5f, 1.0f, 1.0f, VR::math::vec4(1.0f, 0.0f, 1.0f, 1.0f));
		//mRenderer->Add(rectangle);
		mRenderer->Submit();
		glfwSwapBuffers(mWindow);

		glfwPollEvents();
	}
	glfwTerminate();
}

void OpenGLApp::setRenderer(Renderer* renderer) {
	mRenderer = renderer;
}

OpenGLApp::~OpenGLApp() {
	if (mRenderer)
		delete mRenderer;
}

} }