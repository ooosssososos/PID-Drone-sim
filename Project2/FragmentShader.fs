#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in float z;


void main()
{
    FragColor = vec4(z,0.5f,0.5f,1.0f);
}