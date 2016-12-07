#pragma once

#include <GL\glew.h>
#include "vec4.h"

namespace VR {
	namespace math {

		struct mat4 {
			union {
				GLfloat data[4 * 4];
				vec4 rows[4];
			};

			vec4 mat4::GetColumn(int index) const;
		};

	}
}