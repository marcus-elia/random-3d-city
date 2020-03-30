#ifndef RANDOM_3D_CITY_BUILDING_H
#define RANDOM_3D_CITY_BUILDING_H

#include "solid.h"
#include "recPrism.h"
//#include "chunk.h"
#include <vector>
#include <memory>

// int points used for the chunks
// in the xz plane
struct Point2D
{
    int x;
    int z;
    bool operator ==(const Point2D& p1)
    {
        return x == p1.x && z == p1.z;
    }
    bool operator !=(const Point2D& p1)
    {
        return x != p1.x || z != p1.z;
    }
};

class Building
{
protected:
    std::vector<std::shared_ptr<Solid>> solids;

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

    std::vector<std::shared_ptr<Solid>> getSolids() const;

    void draw() const;
};



#endif //RANDOM_3D_CITY_BUILDING_H
