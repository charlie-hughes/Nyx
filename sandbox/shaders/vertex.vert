#version 410 core

// Vertex Attributes
layout (location = 0) in vec3  a_Pos;
layout (location = 1) in vec4  a_Colour;
layout (location = 2) in vec2  a_TexCoord;
layout (location = 3) in float a_TexIndex;

// Uniforms
uniform mat4 u_MVP;

// Outputs
out vec4 Colour;

void main() {

    gl_Position = u_MVP * vec4(a_Pos, 1.0f);

    Colour = a_Colour;

}