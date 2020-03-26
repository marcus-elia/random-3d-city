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

    std::vector<std::unique_ptr<Solid>> solids;
public:
    GameManager();

    // Getters
    Player getPlayer() const;
    std::vector<std::unique_ptr<Solid>> getSolids() const;

    // Camera
    Vector3 getCameraLocation() const;
    Vector3 getCameraLookingAt() const;
    Vector3 getCameraUp() const;

    void draw() const;
    void tick();
};
#endif //RANDOM_3D_CITY_GAMEMANAGER_H
