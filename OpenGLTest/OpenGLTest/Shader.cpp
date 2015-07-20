#include "Shader.h"

Shader::Shader(const std::string& filePath)
{
	shaderPath = &filePath;
	shaderID = Load();
}

Shader::~Shader()
{

}

GLuint Shader::Load()
{
	//GLuint program = glCreateProgram();
	//GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertSource;
	std::string fragSource;

	std::ifstream file(*shaderPath);
	
	file.seekg(0, file.end);
	unsigned int length = file.tellg();
	file.seekg(0, file.beg);

	std::string data(length + 1, '\0');
	file.read(&data[0], length);
	
	unsigned int vertPos = data.find("#vert");
	unsigned int fragPos = data.find("#frag");
	vertSource = data.substr(vertPos + 6, fragPos - 6);
	fragSource = data.substr(fragPos);

	/*if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			if (line.find("#vert") != std::string::npos)
			{
				shaderType = ShaderType::VERTEX;
				continue;
			}
			else if (line.find("#frag") != std::string::npos)
			{
				shaderType = ShaderType::FRAGMENT;
				continue;
			}

			switch (shaderType)
			{
			case Shader::VERTEX:
				vertSource += line + "\n";
				break;
			case Shader::FRAGMENT:
				fragSource += line + "\n";
				break;
			default:
				std::cout << "you done bad" << std::endl;
				break;
			}	
		}

		std::cout << vertSource << std::endl;
		std::cout << fragSource << std::endl;
	}
	else
	{
		std::cout << "Error opening shader: " << *shaderPath << std::endl;
	}*/


	//return program;
	return 0;
}