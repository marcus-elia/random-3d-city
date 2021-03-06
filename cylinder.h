#ifndef RANDOM_3D_CITY_CYLINDER_H
#define RANDOM_3D_CITY_CYLINDER_H

#include "solid.h"
#include "movableObject.h"


// Creates an elliptical cylinder whose bases are parallel to the xz plane
// NOTE: in order for collision to work, must be a circular ellipse

class Cylinder : public Solid, public MovableObject
{
private:
    int smoothness;
public:
    Cylinder();
    Cylinder(Point inputCenter, RGBAcolor inputColor,
             double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor);

    void initializeCorners();

    void move(double deltaX, double deltaY, double deltaZ);

    void rotate(double thetaX, double thetaY, double thetaZ);

    void lookAt(Point &p);

    void draw() const;
    void drawLines() const;
    void drawFaces() const;

    std::experimental::optional<Point> correctCollision(Point p, int buffer);

    void printDebugStats();
};

#endif //RANDOM_3D_CITY_CYLINDER_H
