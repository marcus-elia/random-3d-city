// A solid is an abstract class that will be extended by
// prisms, pyramids, spheres
#ifndef RANDOM_3D_CITY_SOLID_H
#define RANDOM_3D_CITY_SOLID_H

#include "drawableObject.h"
#include <vector>
#include <experimental/optional>

class Solid : public DrawableObject
{
protected:
    std::vector<Point> corners;
    double xWidth;
    double yWidth;
    double zWidth;
    RGBAcolor lineColor;
public:
    // Constructors
    Solid();
    Solid(Point inputCenter, RGBAcolor inputColor,
            double inputXWidth, double inputYWidth, double inputZWidth, RGBAcolor inputLineColor);

    // Initialization
    virtual void initializeCorners();

    // Getters
    std::vector<Point> getCorners() const;
    double getXWidth() const;
    double getYWidth() const;
    double getZWidth() const;
    RGBAcolor getLineColor() const;

    // Setter
    void setCorners(std::vector<Point> inputCorners);
    void setXWidth(double inputXWidth);
    void setYWidth(double inputYWidth);
    void setZWidth(double inputZWidth);
    void setLineColor(RGBAcolor inputLineColor);

    // If the p is within buffer of this shape, a corrected position
    // is returned. returns nullopt otherwise.
    virtual std::experimental::optional<Point> correctCollision(Point p, int buffer)=0;

    virtual void printDebugStats()=0;
};

// Returns the distance in the xz plane
double distance2d(Point p1, Point p2);

// 2d directed distance
double directedDistance(double A, double B, double C, double x, double y);

#endif //RANDOM_3D_CITY_SOLID_H
