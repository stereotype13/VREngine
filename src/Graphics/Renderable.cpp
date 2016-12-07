#include "Renderable.h"

namespace VR {
	namespace core {

		void Renderable::AddVertex(Vertex* vertex) {
			mVertices.push_back(vertex);
		}

		Renderable::~Renderable() {
			for (auto& vertex : mVertices) {
				delete vertex;
			}
		}
	}
}