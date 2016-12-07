#pragma once
#include "..\Math\vec3.h"
#include "..\Math\vec4.h"

namespace VR {
	namespace core {

		struct Vertex {
			math::vec3 position;
			math::vec4 color;
		};
	}
}