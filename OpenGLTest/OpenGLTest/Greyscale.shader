#vert
#version 150

in vec2 position;
in vec3 color;

out vec3 Color;

void main()
{
	Color = color;
    gl_Position = vec4(position, 0.0, 1.0);
}

#frag
#version 150

in float Color;

out vec4 outColor;

void main()
{
    outColor = vec4(Color, Color, Color, 1.0);
}