#include <SGCLPCircleDisplay.h>
#include <SGXColourRGBA.h>
#include <SGRVertexBufferObject.h>
#include <SGRElementBufferObject.h>
#include <SGRRenderingProgramme.h>
#include <SGRGraphicsLanguageType.h>
#include <SGRImage.h>
#include <SGRCommandRequest.h>
#include <SGLArray.h>

SGCLPCircleDisplay::SGCLPCircleDisplay(SGXColourRGBA bg){
    (*this).backgroundColour = bg;
    (*this).vbo = nullptr;
    (*this).ebo = nullptr;
    (*this).textureImage = nullptr;
}

SGRRenderingProgramme* SGCLPCircleDisplay::createRenderingProgramme(){
    SGRRenderingProgramme* rp = new SGRRenderingProgramme(this);
    (*rp).setShaderQSBFiles(":/ColoursPlusPlus/circle.vert.qsb", ":/ColoursPlusPlus/circle.frag.qsb");
    (*rp).addUniformBufferObject(16, 1);
    (*rp).addTexture(0);
    (*rp).finaliseShaderResource();
    (*rp).addVertexBufferObject(2 * 4);
    (*rp).addVertexProperty(0, 0, 0, SGRGraphicsLanguageType::Float, 2);
    (*rp).finaliseVertices();
    (*rp).finaliseRenderingProgramme();
    return rp;
}

void SGCLPCircleDisplay::initialise(){
    vbo = new SGRVertexBufferObject(this, 4 * 2 * 4);
    SGLArray<float> vt(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    (*renderingProgramme()).updateDataBuffer(vbo, 0, 4 * 2 * 4, vt.pointerToData(0));
    ebo = new SGRElementBufferObject(this, 2 * 3 * 4);
    SGLArray<int> et(0, 1, 2, 1, 2, 3);
    (*renderingProgramme()).updateDataBuffer(ebo, 0, 2 * 3 * 4, et.pointerToData(0));
    textureImage = new SGRImage(":/ColoursPlusPlus/conjugates.png");
    (*renderingProgramme()).updateTexture(0, textureImage);
    SGLArray<float> ut(backgroundColour.getRedAsFloat(), backgroundColour.getGreenAsFloat(), backgroundColour.getBlueAsFloat(), backgroundColour.getTransparencyAsFloat());
    (*renderingProgramme()).updateShaderUniforms(1, 0, 16, ut.pointerToData(0));
}

void SGCLPCircleDisplay::cleanResourcesOnDestruction(){
    delete vbo;
    delete ebo;
    delete textureImage;
}

void SGCLPCircleDisplay::uploadShaderData(){

}

void SGCLPCircleDisplay::requestRenderCommands(SGRCommandRequest *commandRequest){
    (*commandRequest).addVertexBufferObject(vbo, 0);
    (*commandRequest).chooseElementBufferObject(ebo);
    (*commandRequest).finaliseForDraw();
    (*commandRequest).drawTriangles(2, 0);
}
