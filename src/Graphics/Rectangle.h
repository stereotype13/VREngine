#pragma once
#include "Renderable.h"
#include "..\Math\vec4.h"

namespace VR {
	namespace core {

		class Rectangle : public Renderable {
		public:
			Rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height, const VR::math::vec4& color);
		};

	}
}