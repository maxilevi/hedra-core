/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "fastnoise-simd/FastNoiseSIMD.h"
#define HEDRA_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

    HEDRA_API FastNoiseSIMD* fastnoise_createObject();

    HEDRA_API float* fastnoise_getSimplexFractalSetWithFrequency(FastNoiseSIMD* pointer, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier);

    HEDRA_API void fastnoise_deleteObject(FastNoiseSIMD* pointer);

    HEDRA_API void fastnoise_freeNoise(float* pointer);


#ifdef __cplusplus
}
#endif
