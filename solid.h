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
public:
    // Constructors
    Solid();
    Solid(Point inputCenter, RGBAcolor inputColor);

    // Initialization
    virtual void initializeCorners() = 0;

    // Getter
    std::vector<Point> getCorners() const;

    // Setter
    void setCorners(std::vector<Point> inputCorners);
};

#endif //RANDOM_3D_CITY_SOLID_H
