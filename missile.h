#ifndef RANDOM_3D_CITY_MISSILE_H
#define RANDOM_3D_CITY_MISSILE_H

#include "drawableObject.h"

class Missile
{
private:
    Point location;
    double speed;
    Point velocity;
    double radius;
public:
    Missile();
    Missile(Point inputLocation, double inputSpeed, Point inputVelocity, double inputRadius);

    // Getters
    Point getLocation() const;
    double getSpeed() const;
    Point getVelocity() const;
    double getRadius() const;

    // Setters
    void setLocation(Point inputLocation);
    void setSpeed(double inputSpeed);
    void setVelocity(Point inputVelocity);
    void setRadius(double inputRadius);

    void draw() const;

    // Movement
    void tick();
    bool isOutOfBounds(Point playerLocation, int radius);
};

#endif //RANDOM_3D_CITY_MISSILE_H
