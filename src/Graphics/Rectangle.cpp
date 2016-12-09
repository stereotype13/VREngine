#include "Rectangle.h"

namespace VR {
	namespace core {

		Rectangle::Rectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height, const VR::math::vec4& color) {
			//1
			Vertex* v1 = new Vertex();
			v1->position[0] = x;
			v1->position[1] = y - height;
			v1->position[2] = 0.0f;

			v1->color = color;
			AddVertex(v1);

			//2
			Vertex* v2 = new Vertex();
			v2->position[0] = x + width;
			v2->position[1] = y - height;
			v2->position[2] = 0.0f;

			v2->color = color;
			AddVertex(v2);

			//3
			Vertex* v3 = new Vertex();
			v3->position[0] = x + width;
			v3->position[1] = y;
			v3->position[2] = 0.0f;

			v3->color = color;
			AddVertex(v3);

			//4
			Vertex* v4 = new Vertex();
			v4->position[0] = x;
			v4->position[1] = y;
			v4->position[2] = 0.0f;

			v4->color = color;
			AddVertex(v4);

			mIndices = std::vector<unsigned int>{0, 1, 3, 1, 2, 3};
		}
	}
}