#version 450 core
in vec4 outcolour;
in vec4 bgcolour;
in vec2 txpos;
uniform vec2 windowsize;
out vec4 fcolour;
void main(){
	if(windowsize.x > windowsize.y){
		float newx = txpos.x / windowsize.y * windowsize.x;
		if(newx * newx + txpos.y * txpos.y < 0.5 * 0.5){fcolour = outcolour;}
		else{fcolour = bgcolour;}
	}
	else{
		float newy = txpos.y / windowsize.x * windowsize.y;
		if(txpos.x * txpos.x + newy * newy < 0.5 * 0.5){fcolour = outcolour;}
		else{fcolour = bgcolour;}
	}
}
