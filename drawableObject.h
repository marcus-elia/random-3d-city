#ifndef RANDOM_3D_CITY_DRAWABLEOBJECT_H
#define RANDOM_3D_CITY_DRAWABLEOBJECT_H

#include "graphics.h"
#include <cmath>

struct RGBAcolor
{
    double r;
    double g;
    double b;
    double a;
};


struct Point
{
    double x;
    double y;
    double z;
};

class DrawableObject
{
protected:
    Point center;
    RGBAcolor color;
public:
    // Constructors
    DrawableObject();
    DrawableObject(Point inputCenter, RGBAcolor inputColor);

    // Getters
    Point getCenter();
    RGBAcolor getColor();
    // Setters
    void setCenter(Point inputCenter);
    void setColor(RGBAcolor inputColor);

    virtual void draw() const = 0;

    // Makes a call to GL's vertex3f function
    void drawPoint(const Point &p) const;
};

#endif //RANDOM_3D_CITY_DRAWABLEOBJECT_H
