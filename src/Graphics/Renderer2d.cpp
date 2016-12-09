#include "Renderer2d.h"
#include "ShaderSimple.h"

namespace VR {
	namespace core {

		void Renderer2d::setUpShader() {
			String vertexShaderSourcePath = "C:\\Users\\rhodel\\Documents\\Visual Studio 2015\\Projects\\VREngine\\VREngine\\src\\Graphics\\Shaders\\SimpleVertexShader.vertex";
			String fragmentShaderSourcePath = "C:\\Users\\rhodel\\Documents\\Visual Studio 2015\\Projects\\VREngine\\VREngine\\src\\Graphics\\Shaders\\SimpleFragmentShader.fragment";

			std::vector <ShaderSimple::VertexAttribute> vertexAttributes;
			VR::core::ShaderSimple::VertexAttribute location0;
			location0.index = 0;
			location0.size = 3;
			location0.normalized = GL_FALSE;
			location0.stride = 7 * sizeof(GLfloat);
			location0.pointer = (GLvoid*)0;
			vertexAttributes.push_back(location0);

			VR::core::ShaderSimple::VertexAttribute location1;
			location1.index = 1;
			location1.size = 4;
			location1.normalized = GL_FALSE;
			location1.stride = 7 * sizeof(GLfloat);
			location1.pointer = (GLvoid*)(3 * sizeof(GLfloat));
			vertexAttributes.push_back(location1);


			VR::core::ShaderSimple* ss = new VR::core::ShaderSimple(vertexShaderSourcePath, fragmentShaderSourcePath, vertexAttributes);
			mShader = ss;
			mShader->Init();
		}

		Renderer2d::Renderer2d() {
			

			setUpShader();
		}

		void Renderer2d::Begin() {
		
			
			
		}

		void Renderer2d::Add(Renderable* renderable) {
			Renderer::Add(renderable);
		}

		void Renderer2d::Submit() {
			glGenVertexArrays(1, &mVAO);
						
			glBindBuffer(GL_ARRAY_BUFFER, mVAO);
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(Vertex), NULL, GL_STATIC_DRAW);
			mVertexPointer = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

			//0

			mVertexPointer->position[0] = 0.5f;
			mVertexPointer->position[1] = 0.5f;
			mVertexPointer->position[2] = 0.0f;

			mVertexPointer->color[0] = 1.0f;
			mVertexPointer->color[1] = 0.0f;
			mVertexPointer->color[2] = 0.0f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//1
			mVertexPointer->position[0] = 0.5f;
			mVertexPointer->position[1] = -0.5f;
			mVertexPointer->position[2] = 0.0f;

			mVertexPointer->color[0] = 0.0f;
			mVertexPointer->color[1] = 1.0f;
			mVertexPointer->color[2] = 0.0f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//2 
			mVertexPointer->position[0] = -0.5f;
			mVertexPointer->position[1] = -0.5f;
			mVertexPointer->position[2] = 0.0f;

			mVertexPointer->color[0] = 0.0f;
			mVertexPointer->color[1] = 0.0f;
			mVertexPointer->color[2] = 1.0f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//3
			mVertexPointer->position[0] = -0.5f;
			mVertexPointer->position[1] = 0.5f;
			mVertexPointer->position[2] = 0.0f;


			mVertexPointer->color[0] = 1.0f;
			mVertexPointer->color[1] = 1.0f;
			mVertexPointer->color[2] = 0.0f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;
			//New rectangle

			//0

			mVertexPointer->position[0] = 0.4f;
			mVertexPointer->position[1] = -0.75f;
			mVertexPointer->position[2] = 0.5f;

			mVertexPointer->color[0] = 0.25f;
			mVertexPointer->color[1] = 0.25f;
			mVertexPointer->color[2] = 0.5f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//1
			mVertexPointer->position[0] = 0.85f;
			mVertexPointer->position[1] = -0.75f;
			mVertexPointer->position[2] = 0.5f;

			mVertexPointer->color[0] = 0.25f;
			mVertexPointer->color[1] = 0.25f;
			mVertexPointer->color[2] = 0.5f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//2 
			mVertexPointer->position[0] = 0.85f;
			mVertexPointer->position[1] = 0.75f;
			mVertexPointer->position[2] = 0.5f;

			mVertexPointer->color[0] = 0.75f;
			mVertexPointer->color[1] = 0.75f;
			mVertexPointer->color[2] = 0.75f;
			mVertexPointer->color[3] = 1.0f;

			++mVertexPointer;

			//3
			mVertexPointer->position[0] = 0.4f;
			mVertexPointer->position[1] = 0.75f;
			mVertexPointer->position[2] = 0.5f;

			mVertexPointer->color[0] = 0.75f;
			mVertexPointer->color[1] = 0.75f;
			mVertexPointer->color[2] = 0.75f;
			mVertexPointer->color[3] = 1.0f;
#if 0
			mIndexCount = 0;
			while (mRenderables.size() > 0) {
				
				auto& renderable = mRenderables.front();
				//Get vertices
				for (const auto& vertex : renderable->getVertices()) {
					mVertexPointer->position = vertex->position;
					mVertexPointer->color = vertex->color;
					++mVertexPointer;
				}

				//Get vertex indices
				for (const auto& i : renderable->getIndices()) {
					mElementBuffer[mIndexCount] = i;
					++mIndexCount;
				}

				delete renderable;
				mRenderables.pop_front();
			}
#endif
			glUnmapBuffer(GL_ARRAY_BUFFER);

			glGenBuffers(1, &mEBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	
			GLushort indices[] = {  // Note that we start from 0!
				0, 1, 3, // First Triangle
				1, 2, 3,  // Second Triangle
				4, 5, 7,
				5, 6, 7
			};
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, 12, &indices[0], GL_STATIC_DRAW);
			
			glUseProgram(mShader->getShaderProgram());
			glBindBuffer(GL_UNSIGNED_SHORT, mEBO);

			// Position attribute
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
			glEnableVertexAttribArray(0);

			// Color attribute
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);

		}

		Renderer2d::~Renderer2d() {
		
		}
	}
}