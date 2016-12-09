#pragma once

#include "..\common.h"
#include "Shader.h"
#include <vector>

namespace VR {
	namespace core {

		class ShaderSimple : public Shader {
		public:
			struct VertexAttribute {
				GLuint index;
				GLint size;
				GLenum type;
				GLboolean normalized;
				GLsizei stride;
				const GLvoid* pointer;

			};
		private:
			String loadSource(String path);
			std::vector<VertexAttribute> mShaderAttributes;
		public:

			

			ShaderSimple() = default;
			ShaderSimple(const String& vertexShaderSourcePath, const String& fragmentShaderSourcePath, std::vector<VertexAttribute>& shaderAttributes);
			bool loadVertexShaderSource(String path) override;
			bool loadFragmentShaderSource(String path) override;

			void setShaderAttributes(const std::vector<VertexAttribute>& attributes);

			bool Init() override;

			GLuint getShaderProgram() override;

		};
	}
}