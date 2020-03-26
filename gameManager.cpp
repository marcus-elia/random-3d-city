#include "gameManager.h"

GameManager::GameManager()
{
    solids.push_back(std::unique_ptr<RecPrism>(new RecPrism({0, 50, 0}, {0.2,0,1,1},
            30,100, 30, {1,1,1,1})));
}

void GameManager::draw() const
{
    for(auto &s : solids)
    {
        s->draw();
    }
}

void GameManager::tick()
{
    player.tick();
}

Player GameManager::getPlayer() const
{
    return player;
}
std::vector<std::unique_ptr<Solid>> GameManager::getSolids() const
{
    return solids;
}

// Camera
Vector3 GameManager::getCameraLocation() const
{
    return player.getLocation();
}
Vector3 GameManager::getCameraLookingAt() const
{
    return player.getLookingAt();
}
Vector3 GameManager::getCameraUp() const
{
    return player.getUp();
}