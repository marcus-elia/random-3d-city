// A solid is an abstract class that will be extended by
// prisms, pyramids, spheres
#ifndef RANDOM_3D_CITY_SOLID_H
#define RANDOM_3D_CITY_SOLID_H

#include "drawableObject.h"
#include <vector>

class Solid : public DrawableObject
{
protected:
    std::vector<Point> corners;
    double xWidth;
    double yWidth;
    double zWidth;
public:
    // Constructors
    Solid();
    Solid(Point inputCenter, RGBAcolor inputColor, double inputXWidth, double inputYWidth, double inputZWidth);

    // Initialization
    virtual void initializeCorners() = 0;

    // Getters
    std::vector<Point> getCorners() const;
    double getXWidth() const;
    double getYWidth() const;
    double getZWidth() const;

    // Setter
    void setCorners(std::vector<Point> inputCorners);
    void setXWidth(double inputXWidth);
    void setYWidth(double inputYWidth);
    void setZWidth(double inputZWidth);
};

#endif //RANDOM_3D_CITY_SOLID_H
