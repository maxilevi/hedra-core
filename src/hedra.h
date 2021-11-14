/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "fastnoise-simd/FastNoiseSIMD.h"
#include "export.h"
#define HEDRA_API EXPORT

#ifdef __cplusplus
extern "C" {
#endif

    HEDRA_API FastNoiseSIMD* fastnoise_createObject(int seed);

    HEDRA_API void fastnoise_setSeed(FastNoiseSIMD* pointer, int seed);

    HEDRA_API void fastnoise_setFrequency(FastNoiseSIMD* pointer, float frequency);

    HEDRA_API float* fastnoise_getPerlinFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getPerlinSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getSimplexSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getSimplexFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getCubicSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getCubicFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getCellularSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getValueSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getValueFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API void fastnoise_deleteObject(FastNoiseSIMD* pointer);

    HEDRA_API void fastnoise_freeNoise(float* pointer);

    HEDRA_API void fastnoise_setCellularReturnType(FastNoiseSIMD* pointer, FastNoiseSIMD::CellularReturnType returnType);

    HEDRA_API void fastnoise_setFractalGain(FastNoiseSIMD* pointer, float gain);

    HEDRA_API void fastnoise_setFractalLacunarity(FastNoiseSIMD* pointer, float lacunarity);

    HEDRA_API void fastnoise_setFractalOctaves(FastNoiseSIMD* pointer, int octaves);

    HEDRA_API void fastnoise_setFractalType(FastNoiseSIMD* pointer, FastNoiseSIMD::FractalType fractalType);

    HEDRA_API void fastnoise_setPerturbAmp(FastNoiseSIMD* pointer, float amplitude);

    HEDRA_API void fastnoise_setPerturbFrequency(FastNoiseSIMD* pointer, float frequency);

    HEDRA_API void fastnoise_setPerturbType(FastNoiseSIMD* pointer, FastNoiseSIMD::PerturbType perturbType);

#ifdef __cplusplus
}
#endif
