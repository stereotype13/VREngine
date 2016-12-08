#pragma once
#include "..\common.h"
#include <vector>
#include "Renderable.h"
#include "Shader.h"

namespace VR { namespace core {

class Renderer {
private:
	std::vector<Renderable*> mRenderables;
	GLuint mVAO;
	Shader* mShader = NULL;

public:
	Renderer(Shader* shader);
	void Add(Renderable* renderable);
	~Renderer();
};


} }