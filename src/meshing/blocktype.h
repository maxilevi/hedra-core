/*
 * Created by Maximiliano Levi on 24/09/2019.
 */

#ifndef HEDRACORE_BLOCKTYPE_H
#define HEDRACORE_BLOCKTYPE_H

enum BlockType : unsigned char
{
    Air = 0,
    Grass = 1,
    Stone = 2,
    Dirt = 3,
    Water = 4,
    Path = 7,
    Temporal = 8,
    Seafloor = 9,
    StonePath = 10,
    FarmDirt = 11,
    None = 12,
    MaxNums
};

#endif //HEDRACORE_BLOCKTYPE_H
