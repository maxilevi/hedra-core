/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "hedra.h"

#ifdef __cplusplus
extern "C" {
#endif

HEDRA_API FastNoiseSIMD* fastnoise_createObject(int seed)
{
    return FastNoiseSIMD::NewFastNoiseSIMD(seed);
}

HEDRA_API void fastnoise_deleteObject(FastNoiseSIMD* pointer)
{
    delete (pointer);
}

HEDRA_API void fastnoise_setSeed(FastNoiseSIMD* pointer, int seed)
{
    pointer->SetSeed(seed);
}

HEDRA_API void fastnoise_freeNoise(float* noiseSet)
{
    FastNoiseSIMD::FreeNoiseSet(noiseSet);
}

HEDRA_API float* fastnoise_getSimplexFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    float* noiseSet = pointer->GetEmptySet(xSize, ySize, zSize);
    pointer->SetNoiseType(FastNoiseSIMD::NoiseType::SimplexFractal);
    pointer->SetAxisScales(xScale, yScale, zScale);
    pointer->FillNoiseSetWithOffset(noiseSet, xOffset, yOffset, zOffset, xSize, ySize, zSize);
    return noiseSet;
}

HEDRA_API void fastnoise_setFrequency(FastNoiseSIMD* pointer, float frequency)
{
    pointer->SetFrequency(frequency);
}

HEDRA_API float* fastnoise_getSimplexSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    float* noiseSet = pointer->GetEmptySet(xSize, ySize, zSize);
    pointer->SetNoiseType(FastNoiseSIMD::NoiseType::Simplex);
    pointer->SetAxisScales(xScale, yScale, zScale);
    pointer->FillNoiseSetWithOffset(noiseSet, xOffset, yOffset, zOffset, xSize, ySize, zSize);
    return noiseSet;
}


#ifdef __cplusplus
}
#endif