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
	GraphicsObject(TextureObject * texture);
	virtual ~GraphicsObject();


private:




};

#endif /* GRAPHICSOBJECT_H_ */
