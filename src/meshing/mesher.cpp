/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#include "mesher.h"
#include "marchingcubes.h"

void polygoniseCell(SampledBlock*** Gridgrid, const gridCell& cell, bool processColors, const bool* next, vertexData* staticData, vec3* vertexBuffer, triangle* triangleBuffer)
{
    int triangleCount = marchingcubes::polygonise(0, cell, vertexBuffer, triangleBuffer);
    vec4 color;
    if (processColors)
    {
        //var regionPosition = new Vector3(Cell.P[0].X + OffsetX, 0, Cell.P[0].Z + OffsetZ);
        //var region = Cache.GetAverageRegionColor(regionPosition);
        //color = this->helper->GetColor(Grid, ref Cell, region, ref normal);
        color = vec4(.5f, .5f, .5f, 1f);
    }
    marchingcubes::build(staticData, color, triangleBuffer, triangleCount, next);
}

void iterateAndBuild(SampledBlock[][][] densityGrid, Block[][][] Blocks, ref bool failed, ref bool hasWater, bool ProcessWater, bool ProcessColors, RegionCache Cache, VertexData blockData, VertexData waterData)
{
    bool next = false;
    bool failed = false;
    triangle triangleBuffer[9];
    vec3 vertexBuffer[12];
    gridCell cell;
    for (int x = 0; x < _boundsX && !failed; x ++)
    {
        next = !next;
        for (int y = 0; y < _boundsY && !failed; y ++)
        {
            for (int z = 0; z < _boundsZ && !failed; z ++)
            {
                next = !next;

            }
        }
    }
}