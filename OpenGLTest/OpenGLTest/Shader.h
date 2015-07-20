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

	const std::string* shaderPath;
	ShaderType shaderType = ShaderType::NONE;

public:
	GLuint shaderID;
	Shader(const std::string& filePath);
	~Shader();

private:
	GLuint Load();
};

#endif SHADER_H