/*
 * ShaderHandler.cpp
 *
 *  Created on: Feb 19, 2019
 *      Author: twhite
 */

#include "ShaderHandler.h"

ShaderHandler::ShaderHandler(Shader * vertexShader, Shader * fragmentShader) {

	this->vertexShader = vertexShader;
	this->fragmentShader = fragmentShader;
	this->shaderProgram = 0;



}

void ShaderHandler::use(){

	glUseProgram(this->shaderProgram);

}

void ShaderHandler::compile(){

	this->vertexShader->compile();
	this->fragmentShader->compile();

	this->shaderProgram = glCreateProgram();

	glAttachShader(this->shaderProgram, this->vertexShader->getShader());
	glAttachShader(this->shaderProgram, this->fragmentShader->getShader());
	glLinkProgram(this->shaderProgram);

	{
		int success;
		char * infoLog = new char[512];

		glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
		if(!success) {
			glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);

			std::cout << "ERROR::GL_PROGRAM::LINK::FAILED" << infoLog << std::endl;

			glfwTerminate();
		}

		delete infoLog;

	}

}

void ShaderHandler::setFloat(const std::string &name, float value) const{
	int location = glGetUniformLocation(this->shaderProgram, name.c_str());
	glUniform1f(location, value);

}

void ShaderHandler::setFloat2f(const std::string &name, glm::vec2 value) const{
	int location = glGetUniformLocation(this->shaderProgram, name.c_str());
	glUniform2fv(location, 1, glm::value_ptr(value));
}


void ShaderHandler::setFloat4x4m(const std::string &name, glm::mat4x4 mat) const{
	int location = glGetUniformLocation(this->shaderProgram, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}


ShaderHandler::~ShaderHandler() {

	delete this->vertexShader;
	delete this->fragmentShader;
}

