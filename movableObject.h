#ifndef RANDOM_3D_CITY_MOVABLEOBJECT_H
#define RANDOM_3D_CITY_MOVABLEOBJECT_H

#include "drawableObject.h"

class MovableObject
{
protected:
    // The forward vector and right vector. These will guide rotations
    Point forwardCartesian, forwardSpherical;
    Point rightCartesian, rightSpherical;
public:
    // Initially, the thing is facing straight down the + z-axis
    MovableObject();


    virtual void move(double deltaX, double deltaY, double deltaZ) = 0;

    virtual void rotate(double thetaX, double thetaY, double thetaZ) = 0;

    virtual void lookAt(Point &p) = 0;
};

// This assumes r = 1
Point cartesianToSpherical(Point &p);

#endif //RANDOM_3D_CITY_MOVABLEOBJECT_H
