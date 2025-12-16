#version 310 es
precision highp float;
precision highp int;
layout(std140, binding = 1) uniform data_{
    vec4 foregroundColour;
    vec4 backgroundColour;
} data;

layout(location = 0) in vec2 vertexCoords;
layout(location = 0) out vec4 outColour;

void main(){
    vec2 currentValue = vec2(0.0f, 0.0f);
    for(int i=0; i<500; i++){
        currentValue = vec2(currentValue.x * currentValue.x - currentValue.y * currentValue.y, 2.0f * currentValue.x * currentValue.y) + vertexCoords;
        if(currentValue.x * currentValue.x + currentValue.y * currentValue.y > 4.0f){break;}
    }
    if(currentValue.x * currentValue.x + currentValue.y * currentValue.y > 4.0f){outColour = data.backgroundColour;}
    else{outColour = data.foregroundColour;}
}
