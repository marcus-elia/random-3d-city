#include "solid.h"

Solid::Solid() : DrawableObject()
{
    initializeCorners();
}

Solid::Solid(Point inputCenter, RGBAcolor inputColor) : DrawableObject(inputCenter, inputColor)
{
    initializeCorners();
}

std::vector<Point> Solid::getCorners() const
{
    return corners;
}

void Solid::setCorners(std::vector<Point> inputCorners)
{
    corners = inputCorners;
}

