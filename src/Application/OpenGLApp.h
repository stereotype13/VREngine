#pragma once
#include "..\common.h"
#include "Application.h"
#include "..\Graphics\Renderer.h"
#include <GLFW\glfw3.h>

namespace VR { namespace core {

class OpenGLApp : public Application {
private:
	GLFWwindow* mWindow;
	String mTitle;
	Renderer* mRenderer = NULL;
public:
	OpenGLApp(String title = "Window Title");
	virtual void setRenderer(Renderer* renderer);
	void Run();
	~OpenGLApp();
};

} }