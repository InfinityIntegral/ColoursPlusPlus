#version 450 core
layout(location = 0) in vec2 pos;
uniform uint displaycolour;
uniform uint blankcolour;
out vec4 outcolour;
out vec4 bgcolour;
out vec2 txpos;
void main(){
	gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);
	outcolour = vec4(float(uint(0xFF) & (displaycolour >> 24)) / 255.0, float(uint(0xFF) & (displaycolour >> 16)) / 255.0, float(uint(0xFF) & (displaycolour >> 8)) / 255.0, 1.0);
	bgcolour = vec4(float(uint(0xFF) & (blankcolour >> 24)) / 255.0, float(uint(0xFF) & (blankcolour >> 16)) / 255.0, float(uint(0xFF) & (blankcolour >> 8)) / 255.0, 1.0);
	txpos = pos;
}
