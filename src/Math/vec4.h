#pragma once


#include <GL\glew.h>


namespace VR {
	namespace math {

		struct vec4 {
			GLfloat mData[4];

			vec4() = default;
			vec4(GLfloat x1, GLfloat x2, GLfloat x3, GLfloat x4);
			GLfloat& operator[](int index);
		};
	}
}