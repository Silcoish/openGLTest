#ifndef H_TEXTURE
#define H_TEXTURE

#include <SDL_opengl.h>
#include <SDL_image.h>
#include <string>

class Texture
{
private:
	std::string fileLocation;
public:
	GLuint textureID;

public:
	Texture(const std::string& path);
	void LoadTexture();
};

#endif