#include "vec3.h"

namespace VR {
	namespace math {

		vec3::vec3(GLfloat x1, GLfloat x2, GLfloat x3) {
			mData[0] = x1;
			mData[1] = x2;
			mData[2] = x3;
		}

		GLfloat& vec3::operator[](int index) {
			return mData[index];
		}

	}
}