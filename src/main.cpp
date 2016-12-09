#include <iostream>
#include "Graphics\Renderer2d.h"
#include "Application\OpenGLApp.h"
#include "common.h"
#include <vector>





int main() {
	
	VR::core::OpenGLApp theApp("Hello, World");
	theApp.setRenderer(new VR::core::Renderer2d());
	
	theApp.Run();
	return 0;
}