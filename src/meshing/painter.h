/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#ifndef HEDRACORE_PAINTER_H
#define HEDRACORE_PAINTER_H


#include "block.h"
#include "marchingcubes.h"

typedef block (*neighbourLookup)(int, int, int);

struct painter {
    block* samplingGrid;
    int _sampleWidth;
    int _sampleHeight;
    int samplingGridSizeX;
    int samplingGridSizeY;
    int _boundsX;
    int _boundsY;
    int _boundsZ;
    neighbourLookup getNeighbourBlock;

    void createCell(gridCell* Cell, int x, int y, int z, bool isWaterCell, int lod, bool* success);
    block getBlock(int _x, int _y, int _z);
    float getSample(int x, int y, int z, unsigned char* type);
    float getSampleOrNeighbour(int x, int y, int z, unsigned char* type);
};


#endif //HEDRACORE_PAINTER_H
