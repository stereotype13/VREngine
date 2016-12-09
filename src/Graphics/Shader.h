#pragma once

#include "..\common.h"

#include <GL\glew.h>

namespace VR {
	namespace core {

		class Shader {
		protected:
			String mVertexShaderSource;
			String mFragmentShaderSource;
			GLuint mVertexShader, mFragmentShader;
			GLuint mShaderProgram;


		public:
			virtual bool loadVertexShaderSource(String path) = 0;
			virtual bool loadFragmentShaderSource(String path) = 0;
			//Override this to compile and use the shader
			virtual bool Init() = 0;
			virtual GLuint getShaderProgram() = 0;
		};
	}
}