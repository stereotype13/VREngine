#include "Renderable.h"

namespace VR {
	namespace core {

		void Renderable::AddVertex(Vertex* vertex) {
			mVertices.push_back(vertex);
		}

		void Renderable::AddIndex(unsigned int index) {
			mIndices.push_back(index);
		}

		std::vector<Vertex*>& Renderable::getVertices() {
			return mVertices;
		}

		std::vector<unsigned int>& Renderable::getIndices() {
			return mIndices;
		}

		Renderable::~Renderable() {
			for (auto& vertex : mVertices) {
				delete vertex;
			}
		}
	}
}