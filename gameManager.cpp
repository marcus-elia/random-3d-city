#include "gameManager.h"

GameManager::GameManager()
{
    solids.push_back(std::unique_ptr<RecPrism>(new RecPrism({0, 50, 0}, {0.2,0,1,1},
            30,100, 30, {1,1,1,1})));
}


void GameManager::reactToMouseMovement(double theta)
{
    player.updateLookingAt(theta);
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

    if(player.whatChunk() != player.getCurrentChunk())
    {
        std::cout << pointToInt({player.whatChunk().x/1024, player.whatChunk().z/1024}) << std::endl;
        player.setCurrentChunk(player.whatChunk());
    }
}

Player GameManager::getPlayer() const
{
    return player;
}
/*std::vector<std::unique_ptr<Solid>> GameManager::getSolids() const
{
    return solids;
}*/
bool GameManager::getWKey()
{
    return wKey;
}
bool GameManager::getAKey()
{
    return aKey;
}
bool GameManager::getSKey()
{
    return sKey;
}
bool GameManager::getDKey()
{
    return dKey;
}
bool GameManager::getRKey()
{
    return rKey;
}
bool GameManager::getCKey()
{
    return cKey;
}

void GameManager::setWKey(bool input)
{
    wKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
}
void GameManager::setAKey(bool input)
{
    aKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
}
void GameManager::setSKey(bool input)
{
    sKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
}
void GameManager::setDKey(bool input)
{
    dKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
}
void GameManager::setRKey(bool input)
{
    rKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
}
void GameManager::setCKey(bool input)
{
    cKey = input;
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
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