#version 450 core
in vec4 outcolour;
in float nxpos;
in float evalcolour;
out vec4 fcolour;
void main(){
	if(evalcolour < 0.5){fcolour = outcolour;}
	else{
		float xpos = ((nxpos + 5.8 / 6.0) / 11.6 * 6.0) - 20.0 / 153.0;
		if(xpos < 0.0){xpos += 1.0;}
		else if(xpos > 1.0){xpos -= 1.0;}
		if(xpos < 1.0 / 6.0){fcolour = vec4(1.0, 6.0 * xpos, 0.0, 1.0);}
		else if(xpos < 2.0 / 6.0){fcolour = vec4(1.0 - 6.0 * (xpos - 1.0 / 6.0), 1.0, 0.0, 1.0);}
		else if(xpos < 3.0 / 6.0){fcolour = vec4(0.0, 1.0, 6.0 * (xpos - 2.0 / 6.0), 1.0);}
		else if(xpos < 4.0 / 6.0){fcolour = vec4(0.0, 1.0 - 6.0 * (xpos - 3.0 / 6.0), 1.0, 1.0);}
		else if(xpos < 5.0 / 6.0){fcolour = vec4(6.0 * (xpos - 4.0 / 6.0), 0.0, 1.0, 1.0);}
		else{fcolour = vec4(1.0, 0.0, 1.0 - 6.0 * (xpos - 5.0 / 6.0), 1.0);}
	}
}
