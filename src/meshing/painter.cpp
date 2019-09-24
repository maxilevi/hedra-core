#include "painter.h"
#include "../mathf.h"
#include "blocktype.h"

const int BLOCK_SIZE = 4;

block painter::getBlock(int _x, int _y, int _z)
{
    return this->samplingGrid[_x * this->samplingGridSizeX * this->samplingGridSizeY + _y * this->samplingGridSizeX + _z];
}

float painter::getSample(int x, int y, int z, unsigned char* type)
{
    int x2 = (x / _sampleWidth);
    int y2 = (y / _sampleHeight);
    int z2 = (z / _sampleWidth);

    *type = getBlock(x2, y2, z2).type;
    return trilinearInterpolation(
            getBlock(x2,y2,z2).density, getBlock(x2 + 1,y2,z2).density,
            getBlock(x2,y2 + 1,z2).density, getBlock(x2 + 1,y2 + 1,z2).density,
            getBlock(x2,y2,z2 + 1).density, getBlock(x2 + 1,y2,z2 + 1).density,
            getBlock(x2,y2 + 1,z2 + 1).density, getBlock(x2 + 1,y2 + 1,z2 + 1).density,
            (x % _sampleWidth) / (float) _sampleWidth,
            (y % _sampleHeight) / (float) _sampleHeight,
            (z % _sampleWidth) / (float) _sampleWidth
    );
}

void buildCell(gridCell* Cell, int X, int Y, int Z, int lod)
{
    int blockSizeLod = BLOCK_SIZE * lod;
    Cell->position[0] = vec3(X * BLOCK_SIZE, Y * BLOCK_SIZE, Z * BLOCK_SIZE);
    Cell->position[1] = vec3(blockSizeLod + Cell->position[0].X, Cell->position[0].Y, Cell->position[0].Z);
    Cell->position[2] = vec3(blockSizeLod + Cell->position[0].X, Cell->position[0].Y, blockSizeLod + Cell->position[0].Z);
    Cell->position[3] = vec3(Cell->position[0].X, Cell->position[0].Y, blockSizeLod + Cell->position[0].Z);
    Cell->position[4] = vec3(Cell->position[0].X, BLOCK_SIZE + Cell->position[0].Y, Cell->position[0].Z);
    Cell->position[5] = vec3(blockSizeLod + Cell->position[0].X, BLOCK_SIZE + Cell->position[0].Y, Cell->position[0].Z);
    Cell->position[6] = vec3(blockSizeLod + Cell->position[0].X, BLOCK_SIZE + Cell->position[0].Y, blockSizeLod + Cell->position[0].Z);
    Cell->position[7] = vec3(Cell->position[0].X, BLOCK_SIZE + Cell->position[0].Y, blockSizeLod + Cell->position[0].Z);
}

float painter::getSampleOrNeighbour(int x, int y, int z, unsigned char* type)
{
    y = min(y, _boundsY - _sampleHeight - 1);
    if (x <= 0 || z <= 0 || x >= _boundsX - 1 || z >= _boundsZ - 1 || _sampleWidth == 1 && _sampleHeight == 1)
    {
        block b = getNeighbourBlock(x, y, z);
        *type = b.type;
        return b.density;
    }
    else
    {
        return getSample(x, y, z, type);
    }
}

void painter::createCell(gridCell* Cell, int x, int y, int z, bool isWaterCell, int lod, bool* success)
{
    *success = true;
    buildCell(Cell, x, y, z, lod);

    for (int i = 0; i < 8; i++)
    {
        int posX = (int) (Cell->position[i].X / BLOCK_SIZE);
        int posY = (int) (Cell->position[i].Y / BLOCK_SIZE);
        int posZ = (int) (Cell->position[i].Z / BLOCK_SIZE);

        if (isWaterCell)
        {
            Cell->type[i] = getNeighbourBlock(posX, posY, posZ).type;
            Cell->density[i] = Cell->type[i] == BlockType::Water ? 1 : 0;
        }
        else
        {
            Cell->density[i] = getSampleOrNeighbour(posX, posY, posZ, &Cell->type[i]);
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (Cell->type[i] == BlockType::Temporal && y < _boundsY-2)
        {
            *success = false;
            Cell->type[i] = BlockType::Air;
        }
    }
}