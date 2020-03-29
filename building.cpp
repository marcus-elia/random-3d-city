#include "building.h"

Building::Building()
{
    topLeft = {0,0};
    sideLength = 32;

    height = 200;
    color = {0,0.4,1,1};
    edgeColor = {.9,.9,.9, 1};
}
Building::Building(Point2D inputTopLeft, int inputSideLength, int inputHeight,
        RGBAcolor inputColor, RGBAcolor inputEdgeColor)
{
    topLeft = inputTopLeft;
    sideLength = inputSideLength;
    height = inputHeight;
    color = inputColor;
    edgeColor = inputEdgeColor;
}

std::vector<Solid> Building::getSolids() const
{
    return solids;
}

void Building::draw() const
{
    for(const Solid &s : solids)
    {
        s.draw();
    }
}
