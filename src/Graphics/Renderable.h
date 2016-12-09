#pragma once

#include "Vertex.h"
#include <vector>

namespace VR { namespace core {

class Renderable {
protected:
	std::vector<Vertex*> mVertices;
	std::vector<unsigned int> mIndices;
public:
	void AddVertex(Vertex* vertex);
	void AddIndex(unsigned int index);
	std::vector<Vertex*>& getVertices();
	std::vector<unsigned int>& getIndices();
	~Renderable();
};

} }