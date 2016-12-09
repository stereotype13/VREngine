#include "ShaderSimple.h"
#include <stdlib.h>

namespace VR {
	namespace core {

		ShaderSimple::ShaderSimple(const String& vertexShaderSourcePath, const String& fragmentShaderSourcePath, std::vector<VertexAttribute>& shaderAttributes) {
			if (!loadVertexShaderSource(vertexShaderSourcePath)) {
				LOG("Error loading vertex shader source code.");
				return;
			}

			if (!loadFragmentShaderSource(fragmentShaderSourcePath)) {
				LOG("Error loading fragment shader source code.");
				return;
			}

			setShaderAttributes(shaderAttributes);
		}

		String ShaderSimple::loadSource(String path) {
			FILE* file;
	
			size_t fileLength, readLength;
			file = fopen(path.c_str(), "r");
			if (!file) {
				LOG("Error: Shader source file not found.");
				return 0;
			}
			fseek(file, 0, SEEK_END);
			fileLength = ftell(file);
			fseek(file, 0, SEEK_SET);
			String buffer(fileLength, 0);
	
			readLength = fread(&buffer[0], 1, fileLength, file);
			buffer[fileLength] = '\0';
			fclose(file);

			return buffer;
		}

		bool ShaderSimple::loadVertexShaderSource(String path) {
			
			String source = loadSource(path);
			if (source[0]) {
				mVertexShaderSource = source;
				return true;
			}
			

			return false;
		}

		bool ShaderSimple::loadFragmentShaderSource(String path) {

			String source = loadSource(path);
			if (source[0]) {
				mFragmentShaderSource = source;
				return true;
			}


			return false;
		}

		void ShaderSimple::setShaderAttributes(const std::vector<VertexAttribute>& attributes) {
			mShaderAttributes = attributes;
		}

		bool ShaderSimple::Init() {
			int isCompiled;
			int maxLength;
			int isLinked;
				
			//Compile vertex shader
			mVertexShader = glCreateShader(GL_VERTEX_SHADER);
			const char* vertexShaderSource = mVertexShaderSource.c_str();
			glShaderSource(mVertexShader, 1, &vertexShaderSource, 0);
			
			glCompileShader(mVertexShader);

			
			glGetShaderiv(mVertexShader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled == GL_FALSE) {
			
				glGetShaderiv(mVertexShader, GL_INFO_LOG_LENGTH, &maxLength);

				char* vertexInfoLog = (char*)malloc(maxLength);
				glGetShaderInfoLog(mVertexShader, maxLength, &maxLength, vertexInfoLog);

				LOG(vertexInfoLog);

				free(vertexInfoLog);
				 
				return false;

			}

			//Compile fragment shader
			mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			const char* fragmentShaderSource = mFragmentShaderSource.c_str();
			glShaderSource(mFragmentShader, 1, &fragmentShaderSource, 0);
			glCompileShader(mFragmentShader);

			glGetShaderiv(mFragmentShader, GL_COMPILE_STATUS, &isCompiled);

			if (isCompiled == GL_FALSE) {
			
				glGetShaderiv(mFragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

				char* fragmentShaderLog = (char*)malloc(maxLength);
				glGetShaderInfoLog(mFragmentShader, maxLength, &maxLength, fragmentShaderLog);

				LOG(fragmentShaderLog);

				free(fragmentShaderLog);

				return false;

			}

			//Link shader program
			mShaderProgram = glCreateProgram();

			glAttachShader(mShaderProgram, mVertexShader);
			glAttachShader(mShaderProgram, mFragmentShader);

			//Set any and all attributes
			/*
			for (const auto& vertexAttribute : mShaderAttributes) {
				glVertexAttribPointer(vertexAttribute.index, vertexAttribute.size, vertexAttribute.type, vertexAttribute.normalized, vertexAttribute.stride, vertexAttribute.pointer);
				glEnableVertexAttribArray(vertexAttribute.index);
			}
			*/

			glLinkProgram(mShaderProgram);

			glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &isLinked);
			if (isLinked == GL_FALSE) {
				glGetProgramiv(mShaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

				char* programInfoLog = (char*)malloc(maxLength);

				glGetProgramInfoLog(mShaderProgram, maxLength, &maxLength, programInfoLog);

				LOG(programInfoLog);

				free(programInfoLog);
				return false;
			}

			//glUseProgram(mShaderProgram);

			return true;
		}

		GLuint ShaderSimple::getShaderProgram() {
			return mShaderProgram;
		}
	}
}