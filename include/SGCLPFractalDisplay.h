#ifndef SGCLPFRACTALDISPLAY_H
#define SGCLPFRACTALDISPLAY_H

#include <SGXColourRGBA.h>
#include <SGRBaseRenderer.h>

class SGRVertexBufferObject;
class SGRElementBufferObject;
class SGCLPFractalDisplay : public SGRBaseRenderer {
public:
    SGCLPFractalDisplay(SGXColourRGBA bg, SGXColourRGBA fg);
    SGXColourRGBA backgroundColour = {};
    SGXColourRGBA foregroundColour = {};
    SGRRenderingProgramme* createRenderingProgramme() override;
    void initialise() override;
    void cleanResourcesOnDestruction() override;
    void uploadShaderData() override;
    void requestRenderCommands(SGRCommandRequest* commandRequest) override;
    SGRVertexBufferObject* vbo;
    SGRElementBufferObject* ebo;
};

#endif // SGCLPFRACTALDISPLAY_H
