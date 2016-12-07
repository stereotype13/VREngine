#pragma once

#include "..\common.h"
#include "Shader.h"

namespace VR {
	namespace core {

		class ShaderSimple : public Shader {
		private:
			char* loadSource(String path);
		public:
			bool loadVertexShaderSource(String path) override;
			bool loadFragmentShaderSource(String path) override;

			bool Init() override;

		};
	}
}