#version 410 core

// In
in vec4 Colour;
in vec2 UV;
in float TexIndex;

// Uniforms

// Out
out vec4 FragColor;

void main() {

    FragColor = Colour;

}