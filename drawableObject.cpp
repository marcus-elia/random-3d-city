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
