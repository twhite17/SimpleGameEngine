/*
 * ShaderHandler.h
 *
 *  Created on: Feb 19, 2019
 *      Author: twhite
 */

#ifndef SHADERHANDLER_H_
#define SHADERHANDLER_H_

#include "Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderHandler {
public:
	ShaderHandler(Shader * vertexShader, Shader * fragmentShader);


	void use();


	void compile();

	// All Setter Fuctions UNIMPLEMENTED

	void setFragmentShader(Shader * fragmentShader);
	void setVertexShader(  Shader * vertexShader);

	// utility uniform functions may be UNIMPLEMENTED
	void setBool		(	const std::string &name, bool value) const;
	void setInt			(	const std::string &name, int value) const;
	void setFloat		(	const std::string &name, float value) const;
	void setFloat2f		(	const std::string &name, glm::vec2 vec) const;
	void setFLoat3f		(	const std::string &name, glm::vec3 vec) const;
	void setFloat4x4m	(	const std::string &name, glm::mat4x4 mat) const;





	// All Getter Functions

	Shader * getFragmentShader();
	Shader * getVertexShader();




	virtual ~ShaderHandler();


private:
	Shader * vertexShader;
	Shader * fragmentShader;

	unsigned int shaderProgram;



};

#endif /* SHADERHANDLER_H_ */
