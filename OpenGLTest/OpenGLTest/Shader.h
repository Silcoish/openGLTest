#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Shader
{
private:
	enum ShaderType
	{
		VERTEX,
		FRAGMENT,
		NONE
	};

	std::string shaderPath;
	ShaderType shaderType = ShaderType::NONE;

public:
	GLuint shaderID;
	Shader(std::string filePath);
	~Shader();
	void Enable();
	void Disable();

private:
	GLuint Load();
};

#endif SHADER_H