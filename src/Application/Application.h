#pragma once
#include <GL\glew.h>

namespace VR { namespace core {

class Application
{

public:
	Application() = default;
	virtual void Run() = 0;
	
};

} }