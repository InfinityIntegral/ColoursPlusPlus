#version 450 core
layout(location = 0) in vec2 pos;
uniform float pointerposition;
uniform int rendertype;
uniform uint colour2;
uniform uint colour3;
out vec4 outcolour;
out float nxpos;
out float evalcolour;

void main(){
	if(rendertype == 1){outcolour = vec4(float(uint(0xFF) & (colour3 >> 24)) / 255.0, float(uint(0xFF) & (colour3 >> 16)) / 255.0, float(uint(0xFF) & (colour3 >> 8)) / 255.0, 1.0);}
	else if(rendertype == 2){outcolour = vec4(float(uint(0xFF) & (colour3 >> 24)) / 255.0, float(uint(0xFF) & (colour3 >> 16)) / 255.0, float(uint(0xFF) & (colour3 >> 8)) / 255.0, 1.0);}
	else if(rendertype == 3){outcolour = vec4(float(uint(0xFF) & (colour2 >> 24)) / 255.0, float(uint(0xFF) & (colour2 >> 16)) / 255.0, float(uint(0xFF) & (colour2 >> 8)) / 255.0, 1.0);}
	else if(rendertype == 4){nxpos = pos.x;}
	if(rendertype != 3){gl_Position = vec4(pos.x, pos.y, 0.0, 1.0);}
	else{gl_Position = vec4(pos.x - 5.8 / 6.0 + 11.6 / 6.0 * pointerposition, pos.y, 0.0, 1.0);}
	if(rendertype != 4){evalcolour = 0.0;}
	else{evalcolour = 1.0;}
}
