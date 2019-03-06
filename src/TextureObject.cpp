/*
 * TextureObject.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

#include "TextureObject.h"

// Note current version isn't very modular and assumes image type is .png
// TODO break constructor into multiple smaller methods that can be indivually called again to modify texture parameters
TextureObject::TextureObject(std::string imagePath, IdGroup * group) {


	 // OpenGL expects images to be defined from the bottom up so it has to be flipped
	stbi_set_flip_vertically_on_load(true);

	// load the image from a file into a standard array of characters (this is very reminisant of C)
	unsigned char * data 	= stbi_load(imagePath.c_str(), &(this->width), &(this->height), &(this->nrChannels), 0);

	this->id 		= group->getNextId();
	this->glId 		= group->glueIdToGroup(group->getMasterId(), this->id);


	glGenTextures(this->glId, &(this->texture));
	glBindTexture(GL_TEXTURE_2D, this->texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	// load and generate the texture

	if (data)
	{
	   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,  this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	   glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
	   std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);



}

void TextureObject::useTexture(){

	glBindTexture(GL_TEXTURE_2D, this->texture);

}

TextureObject::~TextureObject() {


}

