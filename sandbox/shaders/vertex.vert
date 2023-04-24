#version 410 core

// Vertex Attributes
layout (location = 0) in vec3 a_Pos;

// Uniforms
uniform mat4 u_MVP;

// Outputs


void main() {

    gl_Position = u_MVP * vec4(a_Pos, 1.0f);

}