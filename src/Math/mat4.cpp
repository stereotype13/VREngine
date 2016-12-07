#include "mat4.h"

namespace VR {
	namespace math {

		vec4 mat4::GetColumn(int index) const {
			return vec4(data[index + 0 * 4], data[index + 1 * 4], data[index + 2 * 4], data[index + 3 * 4]);
		}

	}
}
