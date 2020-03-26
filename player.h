#ifndef RANDOM_3D_CITY_PLAYER_H
#define RANDOM_3D_CITY_PLAYER_H

#include "graphics.h"

class Player
{
private:
    Vector3 location;
    Vector3 lookingAt;
    Vector3 up;

    double speed;
    Vector3 velocity;
public:
    Player();
    Player(Vector3 inputLocation, Vector3 inputLookingAt, Vector3 inputUp, double inputSpeed);

    // Getters
    Vector3 getLocation() const;
    Vector3 getLookingAt() const;
    Vector3 getUp() const;
    double getSpeed() const;

    // Setters
    void setLocation(Vector3 inputLocation);
    void setLookingAt(Vector3 inputLookingAt);
    void setUp(Vector3 inputUp);
    void setSpeed(double inputSpeed);
    void setVelocity(bool wKey, bool aKey, bool sKey, bool dKey, bool rKey, bool cKey);

    // Movement
    void tick();
};

#endif //RANDOM_3D_CITY_PLAYER_H
