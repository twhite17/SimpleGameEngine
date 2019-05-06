#version 440 core

// location 0 is the vertex co-ordinates
// location 1 is the color of the vertex
// location 2 is the texture mapping co-ordinates

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 outColour;
out vec2 texCoord;

uniform mat4 transform; // the transformation matrix which defines the objects rotation and position


void main()
{	
	vec4 position = vec4(aPos, 1.0);
	
	position = transform * position;
	
	position.x = position.x * (9. / 16); // Aspect ratio transformation (This will later be done with uniforms)
	
	gl_Position = position;
	outColour = aColor;
	texCoord = aTexCoord;
	
}