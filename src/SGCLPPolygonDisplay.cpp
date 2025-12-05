#include <SGCLPPolygonDisplay.h>
#include <SGXColourRGBA.h>
#include <SGRVertexBufferObject.h>
#include <SGRElementBufferObject.h>
#include <SGRRenderingProgramme.h>
#include <SGRGraphicsLanguageType.h>
#include <SGRCommandRequest.h>
#include <SGLArray.h>
#include <SGLFloatConstants.h>
#include <SGLFloatMath.h>

SGCLPPolygonDisplay::SGCLPPolygonDisplay(int vertexCount, SGXColourRGBA fg){
    (*this).foregroundColour = fg;
    (*this).vertexCount = vertexCount;
    (*this).vbo = nullptr;
    (*this).ebo = nullptr;
}

SGRRenderingProgramme* SGCLPPolygonDisplay::createRenderingProgramme(){
    SGRRenderingProgramme* rp = new SGRRenderingProgramme(this);
    (*rp).setShaderQSBFiles(":/ColoursPlusPlus/polygon.vert.qsb", ":/ColoursPlusPlus/polygon.frag.qsb");
    (*rp).addUniformBufferObject(16, 1);
    (*rp).finaliseShaderResource();
    (*rp).addVertexBufferObject(2 * 4);
    (*rp).addVertexProperty(0, 0, 0, SGRGraphicsLanguageType::Float, 2);
    (*rp).finaliseVertices();
    (*rp).finaliseRenderingProgramme();
    return rp;
}

void SGCLPPolygonDisplay::initialise(){
    SGLArray<float> vt(2 * (vertexCount + 1));
    vt.at(0) = 0.0f;
    vt.at(1) = 0.0f;
    for(int i=0; i<vertexCount; i++){
        const float angle = -0.5f * SGLFloatConstants::pi() + 2.0f * SGLFloatConstants::pi() /static_cast<float>(vertexCount) * static_cast<float>(i);
        vt.at(2 + 2 * i) = 0.75f * SGLFloatMath::cosine(angle);
        vt.at(3 + 2 * i) = 0.75f * SGLFloatMath::sine(angle);
    }
    vbo = new SGRVertexBufferObject(this, 4 * 2 * (vertexCount + 1));
    (*renderingProgramme()).updateDataBuffer(vbo, 0, 4 * 2 * (vertexCount + 1), vt.pointerToData(0));
    SGLArray<int> et(3 * vertexCount);
    for(int i=0; i<vertexCount; i++){
        et.at(3 * i) = 0;
        et.at(3 * i + 1) = i + 1;
        et.at(3 * i + 2) = i + 2;
    }
    et.at(3 * vertexCount - 1) = 1;
    ebo = new SGRElementBufferObject(this, 4 * 3 * vertexCount);
    (*renderingProgramme()).updateDataBuffer(ebo, 0, 4 * 3 * vertexCount, et.pointerToData(0));
    SGLArray<float> ut(foregroundColour.getRedAsFloat(), foregroundColour.getGreenAsFloat(), foregroundColour.getBlueAsFloat(), foregroundColour.getTransparencyAsFloat());
    (*renderingProgramme()).updateShaderUniforms(1, 0, 16, ut.pointerToData(0));
}

void SGCLPPolygonDisplay::cleanResourcesOnDestruction(){
    delete vbo;
    delete ebo;
}

void SGCLPPolygonDisplay::uploadShaderData(){

}

void SGCLPPolygonDisplay::requestRenderCommands(SGRCommandRequest *commandRequest){
    (*commandRequest).addVertexBufferObject(vbo, 0);
    (*commandRequest).chooseElementBufferObject(ebo);
    (*commandRequest).finaliseForDraw();
    (*commandRequest).drawTriangles(vertexCount, 0);
}
