#include <SGCLPFractalDisplay.h>
#include <SGXColourRGBA.h>
#include <SGRVertexBufferObject.h>
#include <SGRElementBufferObject.h>
#include <SGRRenderingProgramme.h>
#include <SGRGraphicsLanguageType.h>
#include <SGRCommandRequest.h>
#include <SGLArray.h>

SGCLPFractalDisplay::SGCLPFractalDisplay(SGXColourRGBA bg, SGXColourRGBA fg){
    (*this).backgroundColour = bg;
    (*this).foregroundColour = fg;
    (*this).vbo = nullptr;
    (*this).ebo = nullptr;
}

SGRRenderingProgramme* SGCLPFractalDisplay::createRenderingProgramme(){
    SGRRenderingProgramme* rp = new SGRRenderingProgramme(this);
    (*rp).setShaderQSBFiles(":/ColoursPlusPlus/fractal.vert.qsb", ":/ColoursPlusPlus/fractal.frag.qsb");
    (*rp).addUniformBufferObject(32, 1);
    (*rp).finaliseShaderResource();
    (*rp).addVertexBufferObject(2 * 4);
    (*rp).addVertexProperty(0, 0, 0, SGRGraphicsLanguageType::Float, 2);
    (*rp).finaliseVertices();
    (*rp).finaliseRenderingProgramme();
    return rp;
}

void SGCLPFractalDisplay::initialise(){
    vbo = new SGRVertexBufferObject(this, 4 * 2 * 4);
    SGLArray<float> vt(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    (*renderingProgramme()).updateDataBuffer(vbo, 0, 4 * 2 * 4, vt.pointerToData(0));
    ebo = new SGRElementBufferObject(this, 2 * 3 * 4);
    SGLArray<int> et(0, 1, 2, 1, 2, 3);
    (*renderingProgramme()).updateDataBuffer(ebo, 0, 2 * 3 * 4, et.pointerToData(0));
    SGLArray<float> ut(foregroundColour.getRedAsFloat(), foregroundColour.getGreenAsFloat(), foregroundColour.getBlueAsFloat(), foregroundColour.getTransparencyAsFloat(), backgroundColour.getRedAsFloat(), backgroundColour.getGreenAsFloat(), backgroundColour.getBlueAsFloat(), backgroundColour.getTransparencyAsFloat());
    (*renderingProgramme()).updateShaderUniforms(1, 0, 32, ut.pointerToData(0));
}

void SGCLPFractalDisplay::cleanResourcesOnDestruction(){
    delete vbo;
    delete ebo;
}

void SGCLPFractalDisplay::uploadShaderData(){

}

void SGCLPFractalDisplay::requestRenderCommands(SGRCommandRequest *commandRequest){
    (*commandRequest).addVertexBufferObject(vbo, 0);
    (*commandRequest).chooseElementBufferObject(ebo);
    (*commandRequest).finaliseForDraw();
    (*commandRequest).drawTriangles(2, 0);
}
