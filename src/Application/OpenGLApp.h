#pragma once
#include "..\common.h"
#include "Application.h"
#include <GLFW\glfw3.h>

namespace VR { namespace core {

class OpenGLApp : public Application {
private:
	GLFWwindow* mWindow;
	String mTitle;
public:
	OpenGLApp(String title = "Window Title");
	void Run();

};

} }