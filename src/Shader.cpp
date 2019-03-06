/*
 * Shader.cpp
 * Handles OpenGL Shaders' compilation and usage
 * Intended to be passed to a Shader Handler to be Later used in the overall program
 *
 *  Created on: Feb 19, 2019
 *      Author: twhite
 */

#include "Shader.h"


Shader::Shader(std::string shaderPath, int shaderType) {

	this->shaderType 	= shaderType;
	this->shaderPath 	= shaderPath;
	this->shader 		= 0;
	this->compiled		= false;

	std::string shaderCodeTmp = "";

	std::ifstream reader;

	reader.exceptions (std::ifstream::failbit | std::ifstream::badbit);

	try{

		reader.open(shaderPath);

		if(!reader){

			std::cout  << "ERROR::FSTREAM::CANNOT_OPEN_FILE" << std::endl;

		}

		this->shaderCodeStr = "";

		std::string buffer;

		while(!reader.eof()){

			std::getline(reader, buffer);

			this->shaderCodeStr.append(buffer + "\n");

		}

		this->shaderCode = shaderCodeStr.c_str();


	}catch(std::ifstream::failure e){

		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		std::cout << "FILENAME : " << shaderPath << std::endl;

	}



}


int Shader::compile(){

	shader = glCreateShader(this->shaderType);

	glShaderSource(shader, 1, &(this->shaderCode), NULL);
	glCompileShader(shader);

	{
		// Error Handling in case vertex shader compilation is unsuccessfull
		int success;
		GLchar * infoLog = new GLchar[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success); // check whether compilation was successfull

		if(!success){
			glGetShaderInfoLog(shader, 512, NULL, infoLog); // if not successfull retrieve the log
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
			glfwTerminate(); // assumes a valid glfw context has been available until now. Will later need to be modified to reduce dependancies
			return -1; 		// returns unsucessfull
		}

		delete infoLog;
	}

	this->compiled = true;
	return 0; // executed successfully

}

bool Shader::getCompiled(){
	return this->compiled;
}

unsigned int Shader::getShader(){
	return this->shader;
}




Shader::~Shader() {

	delete this->shaderCode;

}


