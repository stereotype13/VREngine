#include "Renderer.h"

namespace VR { namespace core {

void Renderer::Add(Renderable* renderable) {
	mRenderables.push_back(renderable);
}

Renderer::~Renderer() {
	for (auto& renderable : mRenderables) {
		delete renderable;
	}
}


} }