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