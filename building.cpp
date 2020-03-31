#include "building.h"

Building::Building()
{
    topLeft = {0,0};
    sideLength = 32;

    height = 200;
    color = {0,0.4,1,1};
    edgeColor = {.9,.9,.9, 1};

    Point center = {(double)topLeft.x, (double)height/2, (double)topLeft.z};
    solids.push_back(std::make_shared<RecPrism>(RecPrism(center, color,
            sideLength, height, sideLength, edgeColor)));
}
Building::Building(Point2D inputTopLeft, int inputSideLength, int inputHeight,
        RGBAcolor inputColor, RGBAcolor inputEdgeColor)
{
    topLeft = inputTopLeft;
    sideLength = inputSideLength;
    height = inputHeight;
    color = inputColor;
    edgeColor = inputEdgeColor;
    Point center = {(double)topLeft.x + sideLength/2, (double)height/2, (double)topLeft.z + sideLength/2};
    solids.push_back(std::make_shared<RecPrism>(RecPrism(center, color,
                                                         sideLength, height, sideLength, edgeColor)));
}

std::vector<std::shared_ptr<Solid>> Building::getSolids() const
{
    return solids;
}

void Building::draw() const
{
    for(std::shared_ptr<Solid> s : solids)
    {
        s->draw();
    }
}
