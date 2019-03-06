/*
 * TextureObject.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

#include "TextureObject.h"

TextureObject::TextureObject(std::string imagePath, IdGroup * group) {

	this->image 	= stbi_load(imagePath.c_str(), &(this->width), &(this->height), &(this->nrChannels), 0);
	this->id 		= group->getNextId();

	this->glId = glueId(group->getMasterId(), this->id);


	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


}

TextureObject::~TextureObject() {


}

