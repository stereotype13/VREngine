#include "OpenGLApp.h"


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

		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
			fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

		}
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	}

void OpenGLApp::Run() {
	while (!glfwWindowShouldClose(mWindow)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mWindow);

		glfwPollEvents();
	}
	glfwTerminate();
}

} }