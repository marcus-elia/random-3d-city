#include "solid.h"

Solid::Solid() : DrawableObject()
{
    xWidth = 1;
    yWidth = 1;
    zWidth = 1;
    lineColor = {1,1,1,1};
    initializeCorners();
}

Solid::Solid(Point inputCenter, RGBAcolor inputColor,
        double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor)
: DrawableObject(inputCenter, inputColor)
{
    xWidth = inputXWidth;
    yWidth = inputYWidth;
    zWidth = inputZWidth;
    lineColor = inputLineColor;
    initializeCorners();
}

 void Solid::initializeCorners()
{

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

double distance2d(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.z - p2.z)*(p1.z - p2.z));
}

