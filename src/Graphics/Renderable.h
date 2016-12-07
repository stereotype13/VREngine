#pragma once

#include "Vertex.h"
#include <vector>

namespace VR { namespace core {

class Renderable {
protected:
	std::vector<Vertex*> mVertices;
public:
	void AddVertex(Vertex* vertex);
	~Renderable();
};

} }