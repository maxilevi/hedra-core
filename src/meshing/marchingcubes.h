/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#ifndef HEDRACORE_MARCHINGCUBES_H
#define HEDRACORE_MARCHINGCUBES_H
#include "../vectormath.h"
#include "vertexData.h"

struct gridCell {
    vec3 position[8];
    double density[8];
    unsigned char type[8];
};

struct triangle {
    vec3 vertices[3];
};

class marchingcubes {

public:
    static bool usable(double level, gridCell cell);
    static int polygonise(double level, const gridCell& cell, vec3* vertexBuffer, triangle* triangleBuffer);
    static void build(vertexData* data, const vec4& templateColor, const triangle* triangleBuffer, int triangleCount, bool orientation);
};


#endif //HEDRACORE_MARCHINGCUBES_H
