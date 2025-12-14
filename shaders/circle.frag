#version 310 es
precision highp float;
layout(std140, binding = 1) uniform data_{
    vec4 backgroundColour;
} data;
layout(binding = 0) uniform sampler2D textureSampler;
layout(location = 0) in vec2 vertexCoords;
layout(location = 0) out vec4 outColour;

void main(){
    if(vertexCoords.x * vertexCoords.x + vertexCoords.y * vertexCoords.y > 0.75f * 0.75f){outColour = data.backgroundColour;}
    else{outColour = texture(textureSampler, vertexCoords);}
}
