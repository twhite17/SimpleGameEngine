/*
 * GraphicsObject.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: twhite
 */

#include "GraphicsObject.h"

GraphicsObject::GraphicsObject(TextureObject * texture, IdGroup * objectIdGroup) {

	this->objectIdGroup = objectIdGroup;
	this->texture = texture;

	this->vertexData = new float{};
	this->vertexDataLen = 0;

	this->indexData = new int{};
	this->indexDataLen = 0;

	this->texMapData = new float{};
	this->texMapDataLen = 0;

}

void GraphicsObject::setVertexArray(float * arr, int len){

	this->vertexData = arr;
	this->vertexDataLen = len;

}

void GraphicsObject::setVertexIndices(int * indices, int len){

	this->indexData = indices;
	this->indexDataLen = len;

}

void GraphicsObject::setTexMapArray(float * arr, int len){
	this->texMapData = arr;
	this->texMapDataLen = len;
}

void GraphicsObject::updateProperties(){



}

void GraphicsObject::draw(glm::vec3 position, glm::vec3 rotation){


}

GraphicsObject::~GraphicsObject() {
	// TODO Auto-generated destructor stub
}

