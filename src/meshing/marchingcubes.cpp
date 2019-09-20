/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#include "marchingcubes.h"
#include "tables.h"
#include "vertexData.h"

int getCubeIndex(double level, gridCell cell) {
    int cubeIndex = 0;
    if (cell.density[0] > level) cubeIndex |= 1;
    if (cell.density[1] > level) cubeIndex |= 2;
    if (cell.density[2] > level) cubeIndex |= 4;
    if (cell.density[3] > level) cubeIndex |= 8;
    if (cell.density[4] > level) cubeIndex |= 16;
    if (cell.density[5] > level) cubeIndex |= 32;
    if (cell.density[6] > level) cubeIndex |= 64;
    if (cell.density[7] > level) cubeIndex |= 128;
    return cubeIndex;
}

static bool marchingcubes::usable(double level, gridCell cell)
{
    return EDGE_TABLE[getCubeIndex(level, cell)] != 0;
}

static vec3 vertexInterpolation(double level, vec3 P1, vec3 P2, double valp1, double valp2)
{
    vec4 p1 = vec4(P1, (float) valp1);
    vec4 p2 = vec4(P2, (float) valp2);

    if (p2.length() < p1.length())
    {
        vec4 temp = p1;
        p1 = p2;
        p2 = temp;
    }

    vec3 p;
    if (abs(p1.W - p2.W) > 0.00001)
        p = p1.xyz() + (p2.xyz() - p1.xyz()) / (p2.W - p1.W) * ((float) level - p1.W);
    else
        p = p1.xyz();
    return p;
}

static int marchingcubes::polygonise(double level, const gridCell& cell, vec3* vertexBuffer, triangle* triangleBuffer)
{
    int triangleCount = 0;
    int cubeIndex = getCubeIndex(level, cell);

    /* Cube is entirely in/out of the surface */
    if (EDGE_TABLE[cubeIndex] == 0)
        return triangleCount;

    /* Find the vertices where the surface intersects the cube */
    if ( (EDGE_TABLE[cubeIndex] & 1) > 0 )
        vertexBuffer[0] = vertexInterpolation(level, cell.position[0], cell.position[1], cell.density[0], cell.density[1]);

    if ( (EDGE_TABLE[cubeIndex] & 2) > 0 )
        vertexBuffer[1] = vertexInterpolation(level, cell.position[1], cell.position[2], cell.density[1], cell.density[2]);

    if ( (EDGE_TABLE[cubeIndex] & 4) > 0 )
        vertexBuffer[2] = vertexInterpolation(level, cell.position[2], cell.position[3], cell.density[2], cell.density[3]);

    if ( (EDGE_TABLE[cubeIndex] & 8) > 0 )
        vertexBuffer[3] = vertexInterpolation(level, cell.position[3], cell.position[0], cell.density[3], cell.density[0]);

    if ( (EDGE_TABLE[cubeIndex] & 16) > 0 )
        vertexBuffer[4] = vertexInterpolation(level, cell.position[4], cell.position[5], cell.density[4], cell.density[5]);

    if ( (EDGE_TABLE[cubeIndex] & 32) > 0 )
        vertexBuffer[5] = vertexInterpolation(level, cell.position[5], cell.position[6], cell.density[5], cell.density[6]);

    if ( (EDGE_TABLE[cubeIndex] & 64) > 0 )
        vertexBuffer[6] = vertexInterpolation(level, cell.position[6], cell.position[7], cell.density[6], cell.density[7]);

    if ( (EDGE_TABLE[cubeIndex] & 128) > 0 )
        vertexBuffer[7] = vertexInterpolation(level, cell.position[7], cell.position[4], cell.density[7], cell.density[4]);

    if ( (EDGE_TABLE[cubeIndex] & 256) > 0 )
        vertexBuffer[8] = vertexInterpolation(level, cell.position[0], cell.position[4], cell.density[0], cell.density[4]);

    if ( (EDGE_TABLE[cubeIndex] & 512) > 0 )
        vertexBuffer[9] = vertexInterpolation(level, cell.position[1], cell.position[5], cell.density[1], cell.density[5]);

    if ( (EDGE_TABLE[cubeIndex] & 1024) > 0 )
        vertexBuffer[10] = vertexInterpolation(level, cell.position[2], cell.position[6], cell.density[2], cell.density[6]);

    if ( (EDGE_TABLE[cubeIndex] & 2048) > 0 )
        vertexBuffer[11] = vertexInterpolation(level, cell.position[3], cell.position[7], cell.density[3], cell.density[7]);

    /* Create the triangle */
    for (int i = 0; TRIANGLE_TABLE[cubeIndex][i] != -1; i += 3)
    {
        triangleBuffer[triangleCount].vertices[0] = vertexBuffer[TRIANGLE_TABLE[cubeIndex][i + 0]];
        triangleBuffer[triangleCount].vertices[1] = vertexBuffer[TRIANGLE_TABLE[cubeIndex][i + 1]];
        triangleBuffer[triangleCount].vertices[2] = vertexBuffer[TRIANGLE_TABLE[cubeIndex][i + 2]];
        triangleCount++;
    }
}

static void marchingcubes::build(vertexData* data, const vec4& templateColor, const triangle* triangleBuffer, int triangleCount, bool orientation)
{
    if (triangleCount == 2)
    {
        if (orientation &&
            abs((triangleBuffer[0].vertices[1].xz() - triangleBuffer[1].vertices[1].xz()).lengthSquared()) < 0.0005f &&
            abs((triangleBuffer[1].vertices[0].xz() - triangleBuffer[0].vertices[2].xz()).lengthSquared()) < 0.0005f)
        {
            vec3 vertex2 = triangleBuffer[1].vertices[0];
            vec3 vertex3 = triangleBuffer[0].vertices[0];

            triangleBuffer[0].vertices[0] = triangleBuffer[1].vertices[2];
            triangleBuffer[0].vertices[1] = vertex3;
            triangleBuffer[0].vertices[2] = triangleBuffer[1].vertices[1];

            triangleBuffer[1].vertices[0] = vertex3;
            triangleBuffer[1].vertices[1] = triangleBuffer[1].vertices[2];
            triangleBuffer[1].vertices[2] = vertex2;

        }
    }

    for (int i = 0; i < triangleCount; i++)
    {
        size_t size = data->vertices.size();
        data->indices.push_back((unsigned int) size + 0);
        data->indices.push_back((unsigned int) size + 1);
        data->indices.push_back((unsigned int) size + 2);

        data->vertices.push_back(triangleBuffer[i].vertices[0]);
        data->vertices.push_back(triangleBuffer[i].vertices[1]);
        data->vertices.push_back(triangleBuffer[i].vertices[2]);

        data->colors.push_back(templateColor);
        data->colors.push_back(templateColor);
        data->colors.push_back(templateColor);
    }
}