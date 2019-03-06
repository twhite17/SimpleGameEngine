/*
 * TextureObject.h
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

#ifndef TEXTUREOBJECT_H_
#define TEXTUREOBJECT_H_

#include "stb_image.h"
#include <iostream>
#include "IdGroup.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


// A 2d texture to be used by graphics objects
class TextureObject {


public:

	TextureObject(std::string imagePath, IdGroup * group);

	void useTexture();

	virtual ~TextureObject();


private:

	int width;
	int height;
	int nrChannels;

	unsigned int texture;

	ObjectId id;
	unsigned int glId;



};

#endif /* TEXTUREOBJECT_H_ */
