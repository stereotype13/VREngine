#pragma once

#include "..\common.h"
#include "Shader.h"
#include <vector>

namespace VR {
	namespace core {

		class ShaderSimple : public Shader {
		private:
			String loadSource(String path);
			std::vector<String> mShaderAttributes;
		public:
			bool loadVertexShaderSource(String path) override;
			bool loadFragmentShaderSource(String path) override;

			void setShaderAttributes(const std::vector<String>& attributes);

			bool Init() override;

		};
	}
}