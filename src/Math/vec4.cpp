#include "vec4.h"

namespace VR {
	namespace math {

		vec4::vec4(GLfloat x1, GLfloat x2, GLfloat x3, GLfloat x4) {
			mData[0] = x1;
			mData[1] = x2;
			mData[2] = x3;
			mData[3] = x4;
		}

		GLfloat& vec4::operator[](int index) {
			return mData[index];
		}



	}
}