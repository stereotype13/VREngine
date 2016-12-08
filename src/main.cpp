#include <iostream>
#include "Graphics\ShaderSimple.h"
#include "Graphics\Renderer.h"
#include "Application\OpenGLApp.h"
#include "common.h"





int main() {
	
	VR::core::OpenGLApp theApp("Hello, World");
	VR::core::ShaderSimple* ss = new VR::core::ShaderSimple();
	ss->loadVertexShaderSource("C:\\Users\\rhodel\\Documents\\Visual Studio 2015\\Projects\\VREngine\\VREngine\\src\\Graphics\\Shaders\\SimpleVertexShader.vertex");
	ss->loadFragmentShaderSource("C:\\Users\\rhodel\\Documents\\Visual Studio 2015\\Projects\\VREngine\\VREngine\\src\\Graphics\\Shaders\\SimpleFragmentShader.fragment");
	VR::core::Renderer renderer(ss);
	ss->Init();
	theApp.Run();
	return 0;
}