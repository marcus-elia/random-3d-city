#include "player.h"
#include <cmath>

Player::Player()
{
    location = {80, 30, 60.0};
    lookingAt = {0,30,0};
    up = {0, 1, 0};
    speed = 2;
    velocity = {0,0,0};
}
Player::Player(Vector3 inputLocation, Vector3 inputLookingAt, Vector3 inputUp, double inputSpeed)
{
    location = inputLocation;
    lookingAt = inputLookingAt;
    up = inputUp;
    speed = inputSpeed;
    velocity = {0,0,0};
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


void Player::setVelocity(bool wKey, bool aKey, bool sKey, bool dKey, bool rKey, bool cKey)
{
    bool forward = wKey && !sKey;
    bool backward = !wKey && sKey;
    bool left = aKey && !dKey;
    bool right = !aKey && dKey;
    bool ascending = rKey && !cKey; // name up already used :(
    bool descending = !rKey && cKey;

    // First figure out the vertical (y) velocity, since that is independent
    if(ascending)
    {
        velocity.y = speed;
    }
    else if(descending)
    {
        velocity.y = -speed;
    }
    else
    {
        velocity.y = 0;
    }

    // The angle the player is facing in the xz plane
    double xzAngle = atan2(lookingAt.z - location.z, lookingAt.x - location.x);

    // The angle the player should move based on input
    double angleToMove;
    if(forward)
    {
        if(right)
        {
            angleToMove = xzAngle + PI/4;
        }
        else if(left)
        {
            angleToMove = xzAngle - PI/4;
        }
        else
        {
            angleToMove = xzAngle;
        }
    }
    else if(backward)
    {
        if(right)
        {
            angleToMove = xzAngle - PI - PI/4;
        }
        else if(left)
        {
            angleToMove = xzAngle - PI + PI/4;
        }
        else
        {
            angleToMove = xzAngle - PI;
        }
    }
    else
    {
        if(right)
        {
            angleToMove = xzAngle + PI/2;
        }
        else if(left)
        {
            angleToMove = xzAngle - PI/2;
        }
        else
        {
            velocity.x = 0;
            velocity.z = 0;
            return;
        }
    }
    velocity.x = speed * cos(angleToMove);
    velocity.z = speed * sin(angleToMove);
}

void Player::tick()
{
    location.x += velocity.x;
    lookingAt.x += velocity.x;
    location.y += velocity.y;
    lookingAt.y += velocity.y;
    location.z += velocity.z;
    lookingAt.z += velocity.z;
}