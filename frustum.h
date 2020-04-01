#ifndef RANDOM_3D_CITY_FRUSTUM_H
#define RANDOM_3D_CITY_FRUSTUM_H

#include "solid.h"
#include "movableObject.h"

class Frustum : public Solid, public MovableObject
{
private:
    double upperXWidth;
    double upperZWidth;
public:
    Frustum();
    Frustum(Point inputCenter, RGBAcolor inputColor,
             double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor,
             double inputUpperXWidth, double inputUpperZWidth);

    void initializeCorners();

    void move(double deltaX, double deltaY, double deltaZ);

    void rotate(double thetaX, double thetaY, double thetaZ);

    void lookAt(Point &p);

    void draw() const;
    void drawLines() const;
    void drawFaces() const;
};

#endif //RANDOM_3D_CITY_FRUSTUM_H
