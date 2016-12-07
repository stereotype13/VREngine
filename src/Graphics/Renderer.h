#pragma once
#include "..\common.h"
#include <vector>
#include "Renderable.h"

namespace VR { namespace core {

class Renderer {
private:
	std::vector<Renderable*> mRenderables;

public:
	void Add(Renderable* renderable);
	~Renderer();
};


} }