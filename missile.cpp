#include "missile.h"

Missile::Missile()
{
    location = {0, 100, 0};
    speed = 1;
    velocity = {0, -1, 0};
    radius = 10;
}
Missile::Missile(Point inputLocation, double inputSpeed, Point inputVelocity, double inputRadius)
{
    location = inputLocation;
    speed = inputSpeed;
    setVelocity(inputVelocity);
    radius = inputRadius;

}

// Getters
Point Missile::getLocation() const
{
    return location;
}
double Missile::getSpeed() const
{
    return speed;
}
Point Missile::getVelocity() const
{
    return velocity;
}
double Missile::getRadius() const
{
    return radius;
}

// Setters
void Missile::setLocation(Point inputLocation)
{
    location = inputLocation;
}
void Missile::setSpeed(double inputSpeed)
{
    speed = inputSpeed;
}
void Missile::setVelocity(Point inputVelocity)
{
    double normalization = sqrt(inputVelocity.x*inputVelocity.x + inputVelocity.y*inputVelocity.y +
            inputVelocity.z*inputVelocity.z);
    velocity.x = inputVelocity.x / normalization * speed;
    velocity.y = inputVelocity.y / normalization * speed;
    velocity.z = inputVelocity.z / normalization * speed;
}
void Missile::setRadius(double inputRadius)
{
    radius = inputRadius;
}

void Missile::draw() const
{
    glDisable(GL_CULL_FACE);
    glColor4f(0,1,0,1);
    glBegin(GL_QUADS);
    glVertex3f(location.x - 10, location.y, location.z - 10);
    glVertex3f(location.x - 10, location.y, location.z + 10);
    glVertex3f(location.x + 10, location.y, location.z + 10);
    glVertex3f(location.x + 10, location.y, location.z - 10);
    glEnd();
    glEnable(GL_CULL_FACE);
}

void Missile::tick()
{
    location.x += velocity.x;
    location.y += velocity.y;
    location.z += velocity.z;
}
bool Missile::isOutOfBounds(Point playerLocation, int maxDistance)
{
    return location.y < 0 || location.y > 2048 || distanceFormula(location, playerLocation) > maxDistance;
}