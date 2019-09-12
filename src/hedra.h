/*
 * Created by Maximiliano Levi on 10/09/2019.
 */

#include "fastnoise-simd/FastNoiseSIMD.h"
#define HEDRA_API __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

    HEDRA_API FastNoiseSIMD* fastnoise_createObject(int seed);

    HEDRA_API void fastnoise_setSeed(FastNoiseSIMD* pointer, int seed);

    HEDRA_API void fastnoise_setFrequency(FastNoiseSIMD* pointer, float frequency);

    HEDRA_API float* fastnoise_getSimplexFractalSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API float* fastnoise_getSimplexSet(FastNoiseSIMD* pointer, float xOffset, float yOffset, float zOffset, int xSize, int ySize, int zSize, float xScale, float yScale, float zScale);

    HEDRA_API void fastnoise_deleteObject(FastNoiseSIMD* pointer);

    HEDRA_API void fastnoise_freeNoise(float* pointer);


#ifdef __cplusplus
}
#endif
