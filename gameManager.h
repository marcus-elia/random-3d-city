#ifndef RANDOM_3D_CITY_GAMEMANAGER_H
#define RANDOM_3D_CITY_GAMEMANAGER_H

#include <vector>
#include <memory>
#include "recPrism.h"
#include "player.h"

class GameManager
{
private:
    Player player;

    // Controls
    bool wKey, aKey, sKey, dKey, rKey, cKey;

    std::vector<std::unique_ptr<Solid>> solids;
public:
    GameManager();

    // Getters
    Player getPlayer() const;
    std::vector<std::unique_ptr<Solid>> getSolids() const;
    bool getWKey();
    bool getAKey();
    bool getSKey();
    bool getDKey();
    bool getRKey();
    bool getCKey();

    // Setters
    void setWKey(bool input);
    void setAKey(bool input);
    void setSKey(bool input);
    void setDKey(bool input);
    void setRKey(bool input);
    void setCKey(bool input);

    // Camera
    Vector3 getCameraLocation() const;
    Vector3 getCameraLookingAt() const;
    Vector3 getCameraUp() const;

    // Mouse
    void reactToMouseMovement(double theta);

    void draw() const;
    void tick();
};
#endif //RANDOM_3D_CITY_GAMEMANAGER_H
