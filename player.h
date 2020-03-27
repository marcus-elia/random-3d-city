#ifndef RANDOM_3D_CITY_PLAYER_H
#define RANDOM_3D_CITY_PLAYER_H

#include "graphics.h"

class Player
{
private:
    Vector3 location;
    Vector3 lookingAt;
    Vector3 up;

    double speed;     // how fast the player can move
    Vector3 velocity; // current x y and z velocity

    double sensitivity; // turning speed for mouse movement
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

    // Based on which keys are pressed, set the velocity
    void setVelocity(bool wKey, bool aKey, bool sKey, bool dKey, bool rKey, bool cKey);

    // Rotates lookingAt around location in the xz plane
    void rotateLookingAtHorizontal(double theta);

    // Based on the angle of mouse movement, change the lookingat
    void updateLookingAt(double theta);


    // Movement
    void tick();
};

#endif //RANDOM_3D_CITY_PLAYER_H
