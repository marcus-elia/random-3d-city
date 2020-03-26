#include "movableObject.h"

MovableObject::MovableObject()
{
    // + z axis
    forwardCartesian = {0, 0, 1};
    forwardSpherical = {1, 0, 0};
    // - x axis
    rightCartesian = {-1, 0, 0};
    rightSpherical = {1, PI, 0};
}

Point cartesianToSpherical(Point &p)
{
    // handle floating precision error
    if(p.z > 1)
    {
        return {1, atan2(p.y, p.x), 0};
    }
    else if(p.z < -1)
    {
        return {1, atan2(p.y, p.x), PI};
    }
    return {1, atan2(p.y, p.x), acos(p.z)};
}