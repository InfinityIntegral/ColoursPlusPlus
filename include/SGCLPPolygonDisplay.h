#ifndef SGCLPPOLYGONDISPLAY_H
#define SGCLPPOLYGONDISPLAY_H

#include <SGXColourRGBA.h>
#include <SGRBaseRenderer.h>

class SGRVertexBufferObject;
class SGRElementBufferObject;
class SGCLPPolygonDisplay : public SGRBaseRenderer {
public:
    SGCLPPolygonDisplay(int vertexCount, SGXColourRGBA fg);
    int vertexCount;
    SGXColourRGBA foregroundColour = {};
    SGRRenderingProgramme* createRenderingProgramme() override;
    void initialise() override;
    void cleanResourcesOnDestruction() override;
    void uploadShaderData() override;
    void requestRenderCommands(SGRCommandRequest* commandRequest) override;
    SGRVertexBufferObject* vbo;
    SGRElementBufferObject* ebo;
};

#endif // SGCLPPOLYGONDISPLAY_H
