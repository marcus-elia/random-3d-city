#include "gameManager.h"

GameManager::GameManager()
{
    chunkSize = 256;
    renderRadius = 3;
    solids.push_back(std::unique_ptr<RecPrism>(new RecPrism({0, 50, 0}, {0.2,0,1,1},
            30,100, 30, {1,1,1,1})));
    updateCurrentChunks();
}
GameManager::GameManager(int inputChunkSize, int inputRenderRadius)
{
    chunkSize = inputChunkSize;
    renderRadius = inputRenderRadius;
    updateCurrentChunks();
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
    for(auto &c : currentChunks)
    {
        c->draw();
    }
}

void GameManager::tick()
{
    player.tick();

    // If the player is entering a different chunk
    Point2D curPlayerChunk = player.whatChunk();
    if(curPlayerChunk != player.getCurrentChunkCoords())
    {
        std::cout << pointToInt({player.whatChunk().x/256, player.whatChunk().z/256}) << std::endl;
        updateCurrentChunks();
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

void GameManager::updateCurrentChunks()
{
    player.setCurrentChunkCoords(player.whatChunk());

    // Update the list of current chunks
    currentChunks = std::vector<std::shared_ptr<Chunk>>();
    std::vector<Point2D> chunksInRadius = getChunksAroundPointByPoint(player.getCurrentChunkCoords(), renderRadius);
    for(Point2D p : chunksInRadius)
    {
        int index = pointToInt(p);
        if(allSeenChunks.count(index) == 0) // if the chunk has never been seen before
        {
            allSeenChunks[index] = std::make_shared<Chunk>(p, chunkSize);
        }
        currentChunks.push_back(allSeenChunks[index]);
    }
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