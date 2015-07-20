#include "Shader.h"

Shader::Shader(std::string filePath)
{
	shaderPath = filePath;
	shaderID = Load();
}

Shader::~Shader()
{

}

GLuint Shader::Load()
{
	GLuint program = glCreateProgram();

	std::string vertSource;
	std::string fragSource;

	std::ifstream file(shaderPath);
	
	if (file.is_open())
	{
		file.seekg(0, file.end);
		unsigned int length = file.tellg();
		file.seekg(0, file.beg);

		std::string data(length + 1, '\0');
		file.read(&data[0], length);

		unsigned int vertPos = data.find("#vert");
		unsigned int fragPos = data.find("#frag");
		vertSource = data.substr(vertPos + 6, fragPos - 6);
		fragSource = data.substr(fragPos + 6);
	}
	else
	{
		std::cout << "Failed to load shader: " << shaderPath << std::endl;
	}

	//ERROR CHECKING SETUP
	GLint status;
	char buffer[512];

	//VERTEX SHADER
	const char* v = vertSource.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &v, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	glGetShaderInfoLog(vertexShader, 512, NULL, buffer);

	if (status == GL_FALSE)
	{
		std::cout << "You have a vertex error: " << buffer << std::endl;
		glDeleteShader(vertexShader);
	}

	//FRAGMENT SHADER
	const char* f = fragSource.data();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &f, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);

	if (status == GL_FALSE)
	{
		std::cout << "You have a fragment error: " << buffer << std::endl;
		glDeleteShader(fragmentShader);
	}

	//PROGRAM
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glBindFragDataLocation(program, 0, "outColor");
	glLinkProgram(program);

	return program;
}

void Shader::Enable()
{
	glUseProgram(shaderID);
}

void Shader::Disable()
{
	glUseProgram(0);
}