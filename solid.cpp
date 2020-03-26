#include "solid.h"

Solid::Solid() : DrawableObject()
{
    xWidth = 1;
    yWidth = 1;
    zWidth = 1;
    initializeCorners();
}

Solid::Solid(Point inputCenter, RGBAcolor inputColor, double inputXWidth, double inputYWidth, double inputZWidth)
: DrawableObject(inputCenter, inputColor)
{
    xWidth = inputXWidth;
    yWidth = inputYWidth;
    zWidth = inputZWidth;
    initializeCorners();
}

std::vector<Point> Solid::getCorners() const
{
    return corners;
}
double Solid::getXWidth() const
{
    return xWidth;
}
double Solid::getYWidth() const
{
    return yWidth;
}
double Solid::getZWidth() const
{
    return zWidth;
}

void Solid::setCorners(std::vector<Point> inputCorners)
{
    corners = inputCorners;
}
void Solid::setXWidth(double inputXWidth)
{
    xWidth = inputXWidth;
}
void Solid::setYWidth(double inputYWidth)
{
    yWidth = inputYWidth;
}
void Solid::setZWidth(double inputZWidth)
{
    zWidth = inputZWidth;
}

