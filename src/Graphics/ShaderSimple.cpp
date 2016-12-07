#include "ShaderSimple.h"
#include <stdlib.h>

namespace VR {
	namespace core {

		char* ShaderSimple::loadSource(String path) {
			FILE* file;
			char* buffer = NULL;
			int fileLength, readLength;
			file = fopen(path.c_str(), "rw");
			if (!file) {
				LOG("Error: Shader source file not found.");
				return 0;
			}
			fseek(file, 0, SEEK_END);
			fileLength = ftell(file);
			rewind(file);
			buffer = (char*)malloc(sizeof(char) * (fileLength + 1));
			readLength = fread(buffer, sizeof(char), fileLength, file);
			buffer[fileLength] = '\0';
			fclose(file);

			return buffer;
		}

		bool ShaderSimple::loadVertexShaderSource(String path) {
			
			char* source = loadSource(path);
			if (source) {
				mVertexShaderSource.assign(source);
				return true;
			}
			

			return false;
		}

		bool ShaderSimple::loadFragmentShaderSource(String path) {

			char* source = loadSource(path);
			if (source) {
				mFragmentShaderSource.assign(source);
				return true;
			}


			return false;
		}

		bool ShaderSimple::Init() {

		}
	}
}