#ifndef RANDOM_3D_CITY_CUBE_H
#define RANDOM_3D_CITY_CUBE_H

#include "recPrism.h"
#include <vector>

class Cube : public RecPrism
{
private:
    double sideLength;
    std::vector<Point> corners;
    Point rotationSpeed; // the x,y and z rotation speeds
public:
    Cube();
    Cube(Point inputCenter, RGBAcolor inputColor, double inputSideLength, RGBAcolor inputLineColor,
            Point inputRotationSpeed);

    void initializeCorners();

    void move(double deltaX, double deltaY, double deltaZ);

    void rotate(double thetaX, double thetaY, double thetaZ);

    void lookAt(Point &p);

    void draw() const;
    void drawLines() const;
};

// Rotates p around pBase in 3D space
void rotatePointAroundPoint(Point &p, const Point &pBase, double thetaX, double thetaY, double thetaZ);

#endif //RANDOM_3D_CITY_CUBE_H
