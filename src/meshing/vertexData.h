/*
 * Created by Maximiliano Levi on 17/09/2019.
 */

#ifndef HEDRACORE_VERTEXDATA_H
#define HEDRACORE_VERTEXDATA_H

#include <vector>

struct vertexData {
    std::vector<vec3> vertices;
    std::vector<unsigned int> indices;
    std::vector<vec4> colors;
};

#endif //HEDRACORE_VERTEXDATA_H
