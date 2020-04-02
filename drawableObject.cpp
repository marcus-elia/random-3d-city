#include "drawableObject.h"

DrawableObject::DrawableObject()
{
    center = {0,0,0};
    color = {1,1,1,1};
}

DrawableObject::DrawableObject(Point inputCenter, RGBAcolor inputColor)
{
    center = inputCenter;
    color = inputColor;
}

Point DrawableObject::getCenter()
{
    return center;
}
RGBAcolor DrawableObject::getColor()
{
    return color;
}

void DrawableObject::setCenter(Point inputCenter)
{
    center = inputCenter;
}
void DrawableObject::setColor(RGBAcolor inputColor)
{
    color = inputColor;
}

void DrawableObject::drawPoint(const Point &p) const
{
    glVertex3f(p.x, p.y, p.z);
}

double distanceFormula(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) + (p1.z - p2.z)*(p1.z - p2.z));
}