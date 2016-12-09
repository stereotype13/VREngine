#include "Renderer.h"

namespace VR { namespace core {

Renderer::Renderer(Shader* shader) {
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mEBO);
	mShader = shader;
}

void Renderer::Add(Renderable* renderable) {
	mRenderables.push_back(renderable);
}

Renderer::~Renderer() {
	for (auto& renderable : mRenderables) {
		delete renderable;
	}

	if (mShader)
		delete mShader;
}



} }