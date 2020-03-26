#ifndef RANDOM_3D_CITY_GAMEMANAGER_H
#define RANDOM_3D_CITY_GAMEMANAGER_H

#include <vector>
#include "recPrism.h"

class GameManager
{
private:
    std::vector<Solid> solids;
public:
    GameManager();

    void draw() const;
    void tick();
};
#endif //RANDOM_3D_CITY_GAMEMANAGER_H
