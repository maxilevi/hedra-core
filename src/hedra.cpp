/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "hedra.h"

#ifdef __cplusplus
extern "C" {
#endif

HEDRA_API FastNoiseSIMD* fastnoise_createObject()
{
    return FastNoiseSIMD::NewFastNoiseSIMD();
}

HEDRA_API void fastnoise_deleteObject(FastNoiseSIMD* pointer)
{
    delete (pointer);
}

HEDRA_API void fastnoise_freeNoise(float* noiseSet)
{
    FastNoiseSIMD::FreeNoiseSet(noiseSet);
}

HEDRA_API float* fastnoise_getSimplexFractalSetWithFrequency(FastNoiseSIMD* pointer, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier)
{
    return pointer->GetSimplexFractalSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);
}

#ifdef __cplusplus
}
#endif