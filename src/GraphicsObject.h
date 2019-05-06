/*
 * GraphicsObject.h
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

#ifndef GRAPHICSOBJECT_H_
#define GRAPHICSOBJECT_H_


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "stb_image.h"
#include "TextureObject.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


class GraphicsObject {


public:
	GraphicsObject(TextureObject * texture, IdGroup * objectIdGroup);
	virtual ~GraphicsObject();


	void setVertexArray(float * arr, int len);
	void setVertexIndices(int * indices, int len);
	void setTexMapArray(float * arr, int len);

	void updateProperties();	// used to syc vertex and texture data with opengl.
								// Whenever changes are made to these properties this function
								// should be called before attempting any kind of render.

	void draw(glm::vec3 position, glm::vec3 rotation); 	// position and rotation are world space
														// (meaning they are applied after camera postitions are calculated)


private:

	IdGroup * objectIdGroup;
	TextureObject * texture;

	float * vertexData;
	int vertexDataLen;

	int * indexData;
	int indexDataLen;

	float * texMapData;
	int texMapDataLen;




};

#endif /* GRAPHICSOBJECT_H_ */
