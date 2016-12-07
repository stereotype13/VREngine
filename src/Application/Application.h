#pragma once

namespace VR { namespace core {

class Application
{
public:
	Application() = default;
	virtual void Run() = 0;
	
};

} }