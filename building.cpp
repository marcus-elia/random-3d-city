#include "building.h"

Building::Building()
{
    topLeft = {0,0};
    sideLength = 32;

    height = 200;
    color = {0,0.4,1,1};
    edgeColor = {.9,.9,.9, 1};

    buildingType = Plain;

    initializeSolids();
}
Building::Building(Point2D inputTopLeft, int inputSideLength, int inputHeight,
        RGBAcolor inputColor, RGBAcolor inputEdgeColor, typeOfBuilding inputBuildingType)
{
    topLeft = inputTopLeft;
    sideLength = inputSideLength;
    height = inputHeight;
    color = inputColor;
    edgeColor = inputEdgeColor;
    buildingType = inputBuildingType;

    initializeSolids();

}

void Building::initializeSolids()
{
    if(buildingType == Plain)
    {
        Point center = {(double)topLeft.x + sideLength/2, (double)height/2, (double)topLeft.z + sideLength/2};
        solids.push_back(std::make_shared<RecPrism>(RecPrism(center, color,
                                                             sideLength, height, sideLength, edgeColor)));
    }
    else if(buildingType == House)
    {
        Point center = {(double)topLeft.x + sideLength/2, (double)height/2, (double)topLeft.z + sideLength/2};
        solids.push_back(std::make_shared<RecPrism>(RecPrism(center, color,
                                                             sideLength - 5, height, sideLength - 5, edgeColor)));
        Point roofCenter = {center.x, center.y + 3*height/4, center.z};
        solids.push_back(std::make_shared<TriPrism>(TriPrism(roofCenter, color,
                                                             sideLength, height/2, sideLength, edgeColor)));
    }
    else if(buildingType == Skyscraper)
    {
        Point center = {(double)topLeft.x + sideLength/2, (double)3*height/4, (double)topLeft.z + sideLength/2};
        solids.push_back(std::make_shared<RecPrism>(RecPrism(center, color,
                                                             sideLength, 3*height/2, sideLength, edgeColor)));
    }
}

std::vector<std::shared_ptr<Solid>> Building::getSolids() const
{
    return solids;
}
typeOfBuilding Building::getBuildingType() const
{
    return buildingType;
}

void Building::draw() const
{
    for(std::shared_ptr<Solid> s : solids)
    {
        s->draw();
    }
}
