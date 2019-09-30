/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "hedra.h"
#include "meshing/painter.h"
#include "meshing/mesher.h"

#ifdef __cplusplus
extern "C" {
#endif

float* getNoiseSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale, FastNoiseSIMD::NoiseType noiseType)
{
    float* noiseSet = pointer->GetEmptySet(xSize, ySize, zSize);
    pointer->SetNoiseType(noiseType);
    pointer->SetAxisScales(xScale, yScale, zScale);
    pointer->FillNoiseSetWithOffset(noiseSet, xOffset, yOffset, zOffset, xSize, ySize, zSize);
    return noiseSet;
}

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

HEDRA_API float* fastnoise_getPerlinFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::PerlinFractal);
}

HEDRA_API float* fastnoise_getPerlinSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::Perlin);
}

HEDRA_API float* fastnoise_getSimplexSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::Simplex);
}

HEDRA_API float* fastnoise_getSimplexFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::SimplexFractal);
}

HEDRA_API float* fastnoise_getCubicSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::Cubic);
}

HEDRA_API float* fastnoise_getCubicFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::CubicFractal);
}

HEDRA_API float* fastnoise_getCellularSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::Cellular);
}

HEDRA_API float* fastnoise_getValueSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::Value);
}

HEDRA_API float* fastnoise_getValueFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale)
{
    return getNoiseSet(pointer, xOffset, yOffset, zOffset, xSize, ySize, zSize, xScale, yScale, zScale, FastNoiseSIMD::NoiseType::ValueFractal);
}

HEDRA_API void fastnoise_setCellularReturnType(FastNoiseSIMD* pointer, FastNoiseSIMD::CellularReturnType returnType)
{
    pointer->SetCellularReturnType(returnType);
}

HEDRA_API void fastnoise_setFractalGain(FastNoiseSIMD* pointer, float gain)
{
    pointer->SetFractalGain(gain);
}

HEDRA_API void fastnoise_setFractalLacunarity(FastNoiseSIMD* pointer, float lacunarity)
{
    pointer->SetFractalLacunarity(lacunarity);
}

HEDRA_API void fastnoise_setFractalOctaves(FastNoiseSIMD* pointer, int octaves)
{
    pointer->SetFractalOctaves(octaves);
}

HEDRA_API void fastnoise_setFractalType(FastNoiseSIMD* pointer, FastNoiseSIMD::FractalType fractalType)
{
    pointer->SetFractalType(fractalType);
}

HEDRA_API void fastnoise_setFrequency(FastNoiseSIMD* pointer, float frequency)
{
    pointer->SetFrequency(frequency);
}

HEDRA_API void fastnoise_setPerturbType(FastNoiseSIMD* pointer, FastNoiseSIMD::PerturbType perturbType)
{
    pointer->SetPerturbType(perturbType);
}

HEDRA_API void fastnoise_setPerturbAmp(FastNoiseSIMD* pointer, float amplitude)
{
    pointer->SetPerturbAmp(amplitude);
}

HEDRA_API void fastnoise_setPerturbFrequency(FastNoiseSIMD* pointer, float frequency)
{
    pointer->SetPerturbFrequency(frequency);
}

#ifdef __cplusplus
}
#endif