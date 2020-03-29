#ifndef RANDOM_3D_CITY_BUILDING_H
#define RANDOM_3D_CITY_BUILDING_H

#include "solid.h"
#include "chunk.h"
#include <vector>

class Building
{
protected:
    std::vector<Solid> solids;

    // The rectangular base of the building's property
    Point2D topLeft;
    int sideLength;

    int height;
    RGBAcolor color;
    RGBAcolor edgeColor;

public:
    Building();
    Building(Point2D inputTopLeft, int inputSideLength, int inputHeight,
            RGBAcolor inputColor, RGBAcolor inputEdgeColor);

    std::vector<Solid> getSolids() const;

    void draw() const;
};

#endif //RANDOM_3D_CITY_BUILDING_H
