#pragma once

#include "Renderer.h"

#define MAX_SPRITES 100

namespace VR {
	namespace core {


		class Renderer2d : public Renderer {
		private:
			void setUpShader() override;
			Vertex* mVertexPointer;
			unsigned int mElementBuffer[MAX_SPRITES * 2];
			unsigned int mIndexCount;
		public:
			Renderer2d();
			void Begin() override;
			void Add(Renderable* renderable) override;
			void Submit() override;
			~Renderer2d();
		};
		
	}
}
