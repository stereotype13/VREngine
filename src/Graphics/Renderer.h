#pragma once
#include "..\common.h"
#include <deque>
#include "Renderable.h"
#include "Shader.h"

namespace VR { namespace core {

class Renderer {
protected:
	std::deque<Renderable*> mRenderables;
	GLuint mVAO;
	GLuint mEBO;
	Shader* mShader = NULL;

public:
	Renderer() = default;
	Renderer(Shader* shader);
	virtual void setUpShader() = 0;
	virtual void Begin() = 0;
	virtual void Add(Renderable* renderable);
	virtual void Submit() = 0;
	virtual ~Renderer();
};


} }