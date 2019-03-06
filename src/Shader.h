/*
 * Shader.h
 *
 *  Created on: Feb 19, 2019
 *      Author: twhite
 */

#ifndef SHADER_H_
#define SHADER_H_


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader {
public:

	//constructor
	Shader(std::string shaderPath, int shaderType);

	int compile();

	// just a few setter functions, I intend to add these as needed from now on
	void setBool(const std::string &name, bool value);
	void setInt(const std::string &name, int value);
	void setFloat(const std::string &name, float value);


	// getter functions will be added as needed from now on
	unsigned int getShader();

	bool getCompiled();

	//destructor
	virtual ~Shader();

private:

	const char * shaderCode; 		// shadercode source is stored as a c string for opnengl compatibility
	std::string shaderCodeStr;

	std::string shaderPath; 		// incase the shader code itself is later needed to be modified
	int shaderType;			// needed for some OpenGL functions

	unsigned int shader;	// pointer to actual shader obejct has weird syntax since OpenGL is C Based

	bool compiled;


};

#endif /* SHADER_H_ */
