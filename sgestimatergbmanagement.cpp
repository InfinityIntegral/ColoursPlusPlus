#include "sgestimatergbmanagement.h"
#include "sgselectpagemanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"

QString SGEstimateRGBManagement::EstimateRGBs(){
    float r1;
    float g1;
    float b1;
    if(SGSelectPageManagement::selectedtype == 1){
        r1 = 0.0f;
        g1 = 0.0f;
        b1 = 0.0f;
    }
    else if(SGSelectPageManagement::selectedtype == 2){
        r1 = 255.0f;
        g1 = 255.0f;
        b1 = 255.0f;
    }
    else if(SGSelectPageManagement::selectedtype == 3){
        uint c = SGGeneralLibrary::maxsaturatedcolour(SGSelectPageManagement::selectedhue);
        r1 = 0xFF & (c >> 24);
        g1 = 0xFF & (c >> 16);
        b1 = 0xFF & (c >> 8);
    }
    r1 /= 255.0f;
    g1 /= 255.0f;
    b1 /= 255.0f;
    float r0;
    float g0;
    float b0;
    {
        uint c = SGGeneralLibrary::maxsaturatedcolour(SGSelectPageManagement::selectedhue + 0.5f);
        r0 = 0xFF & (c >> 24);
        g0 = 0xFF & (c >> 16);
        b0 = 0xFF & (c >> 8);
    }
    r0 /= 255.0f;
    g0 /= 255.0f;
    b0 /= 255.0f;
    r1 = std::pow(r1, 1.0f / 2.2f);
    g1 = std::pow(g1, 1.0f / 2.2f);
    b1 = std::pow(b1, 1.0f / 2.2f);
    r0 = std::pow(r0, 1.0f / 2.2f);
    g0 = std::pow(g0, 1.0f / 2.2f);
    b0 = std::pow(b0, 1.0f / 2.2f);
    r1 = (175.0f + 400.0f * 3.426f * r1) / (175.0f + 400.0f * 3.426f);
    g1 = (175.0f + 400.0f * 3.426f * g1) / (175.0f + 400.0f * 3.426f);
    b1 = (175.0f + 400.0f * 3.426f * b1) / (175.0f + 400.0f * 3.426f);
    r0 = (175.0f + 400.0f * 3.426f * r0);
    g0 = (175.0f + 400.0f * 3.426f * g0);
    b0 = (175.0f + 400.0f * 3.426f * b0);
    {
        float x = 0.5141f * r1 + 0.3239f * g1 + 0.1604f * b1;
        float y = 0.2651f * r1 + 0.6702f * g1 + 0.0641f * b1;
        float z = 0.0241f * r1 + 0.1228f * g1 + 0.8444f * b1;
        r1 = 0.3897f * x + 0.6890f * y - 0.0787 * z;
        g1 = -0.2298f * x + 1.1834 * y + 0.0464 * z;
        b1 = z;
    }
    r0 = std::log10(r0 * 3.426f / 4.0f / 3.14159265359f);
    g0 = std::log10(g0 * 3.426f / 4.0f / 3.14159265359f);
    b0 = std::log10(b0 * 3.426f / 4.0f / 3.14159265359f);
    float c0 = std::log10(175.0f * 3.426f / 4.0f / 3.14159265359f);
    r1 *= (4.30f / (r0 + 4.30f));
    g1 *= (4.30f / (g0 + 4.30f));
    b1 *= (4.30f / (b0 + 4.30f));
    r1 /= (4.30f / (c0 + 4.30f));
    g1 /= (4.30f / (c0 + 4.30f));
    b1 /= (4.30f / (c0 + 4.30f));
    {
        float x = 1.9102f * r1 - 1.1122f * g1 + 0.2019f * b1;
        float y = 0.3709f * r1 + 0.6291f * g1;
        float z = b1;
        r1 = 2.5655f * x - 1.1668f * y - 0.3988f * z;
        g1 = -1.022f * x + 1.978f * y + 0.044f * z;
        b1 = 0.0754f * x - 0.2543f * y + 1.1893f * z;
    }
    r1 = ((175.0f + 400.0f * 3.426f) * r1 - 175.0f) / (400.0f * 3.426f);
    g1 = ((175.0f + 400.0f * 3.426f) * g1 - 175.0f) / (400.0f * 3.426f);
    b1 = ((175.0f + 400.0f * 3.426f) * b1 - 175.0f) / (400.0f * 3.426f);
    if(r1 < 0){r1 = (-1.0f) * std::pow((-1.0f) * r1, 2.2f);}
    else{r1 = std::pow(r1, 2.2f);}
    if(g1 < 0){g1 = (-1.0f) * std::pow((-1.0f) * g1, 2.2f);}
    else{g1 = std::pow(g1, 2.2f);}
    if(b1 < 0){b1 = (-1.0f) * std::pow((-1.0f) * b1, 2.2f);}
    else{b1 = std::pow(b1, 2.2f);}
    r1 *= 255.0f;
    g1 *= 255.0f;
    b1 *= 255.0f;
    return ("(" + QString::number((int)r1) + ", " + QString::number((int)g1) + ", " + QString::number((int)b1) + ")");
}
