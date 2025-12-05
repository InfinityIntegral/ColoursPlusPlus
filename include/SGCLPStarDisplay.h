#ifndef SGCLPSTARDISPLAY_H
#define SGCLPSTARDISPLAY_H

#include <SGXColourRGBA.h>
#include <SGRBaseRenderer.h>

class SGRVertexBufferObject;
class SGRElementBufferObject;
class SGCLPStarDisplay : public SGRBaseRenderer {
public:
    SGCLPStarDisplay(int vertexCount, SGXColourRGBA fg);
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

#endif // SGCLPSTARDISPLAY_H
