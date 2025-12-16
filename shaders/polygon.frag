#version 310 es
precision highp float;
precision highp int;
layout(std140, binding = 1) uniform data_{
    vec4 foregroundColour;
} data;

layout(location = 0) out vec4 outColour;

void main(){
    outColour = data.foregroundColour;
}
