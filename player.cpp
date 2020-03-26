#include "player.h"

Player::Player()
{
    location = {2.0, 3.0, 6.0};
    lookingAt = {0,0,0};
    up = {0, 1, 0};
    speed = 5;
}
Player::Player(Vector3 inputLocation, Vector3 inputLookingAt, Vector3 inputUp, double inputSpeed)
{
    location = inputLocation;
    lookingAt = inputLookingAt;
    up = inputUp;
    speed = inputSpeed;
}

// Getters
Vector3 Player::getLocation() const
{
    return location;
}
Vector3 Player::getLookingAt() const
{
    return lookingAt;
}
Vector3 Player::getUp() const
{
    return up;
}
double Player::getSpeed() const
{
    return speed;
}

// Setters
void Player::setLocation(Vector3 inputLocation)
{
    location = inputLocation;
}
void Player::setLookingAt(Vector3 inputLookingAt)
{
    lookingAt = inputLookingAt;
}
void Player::setUp(Vector3 inputUp)
{
    up = inputUp;
}
void Player::setSpeed(double inputSpeed)
{
    speed = inputSpeed;
}


void Player::tick()
{
    location.x += speed;
}