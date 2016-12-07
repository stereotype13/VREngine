#pragma once

#include <GL\glew.h>

namespace VR {
	namespace math {

		struct vec3 {
			GLfloat mData[3];

			vec3() = default;
			vec3(GLfloat x1, GLfloat x2, GLfloat x3);
			GLfloat& operator[](int index);
		};
	}
}