#ifndef SGCLPCIRCLEDISPLAY_H
#define SGCLPCIRCLEDISPLAY_H

#include <SGRBaseRenderer.h>
#include <SGXColourRGBA.h>

class SGRVertexBufferObject;
class SGRElementBufferObject;
class SGRImage;
class SGCLPCircleDisplay : public SGRBaseRenderer {
public:
    SGCLPCircleDisplay(SGXColourRGBA bg);
    SGXColourRGBA backgroundColour = {};
    SGRRenderingProgramme* createRenderingProgramme() override;
    void initialise() override;
    void cleanResourcesOnDestruction() override;
    void uploadShaderData() override;
    void requestRenderCommands(SGRCommandRequest* commandRequest) override;
    SGRVertexBufferObject* vbo;
    SGRElementBufferObject* ebo;
    SGRImage* textureImage;
};

#endif // SGCLPCIRCLEDISPLAY_H
