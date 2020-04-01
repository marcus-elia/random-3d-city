#include "gameManager.h"

GameManager::GameManager()
{
    perlinSize = 10;
    png = PerlinNoiseGenerator(10, 10, 1);
    chunkSize = 512;
    renderRadius = 5;
    solids.push_back(std::unique_ptr<RecPrism>(new RecPrism({0, 50, 0}, {0.2,0,1,1},
            30,100, 30, {1,1,1,1})));
    updateCurrentChunks();
}
GameManager::GameManager(int inputChunkSize, int inputRenderRadius, int inputPerlinSize)
{
    chunkSize = inputChunkSize;
    renderRadius = inputRenderRadius;
    perlinSize = inputPerlinSize;
    png = PerlinNoiseGenerator(perlinSize, perlinSize, 1);
    updateCurrentChunks();
}

void GameManager::reactToMouseMovement(double theta)
{
    player.updateLookingAt(theta);
    player.setVelocity(wKey, aKey, sKey, dKey, rKey, cKey);
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

    // Make current chunk red for debug
    /*Point2D p = player.getCurrentChunkCoords();
    glBegin(GL_QUADS);
    glColor4f(1,0,0,1);
    glVertex3f(chunkSize*p.x,1, chunkSize*p.z);
    glVertex3f(chunkSize*p.x,1, chunkSize*p.z + chunkSize);
    glVertex3f(chunkSize*p.x + chunkSize,1, chunkSize*p.z + chunkSize);
    glVertex3f(chunkSize*p.x + chunkSize,1, chunkSize*p.z);

    glEnd();*/
}

void GameManager::tick()
{
    player.tick();

    // If the player is entering a different chunk
    Point2D curPlayerChunk = player.whatChunk();
    if(curPlayerChunk != player.getCurrentChunkCoords())
    {
        //std::cout << pointToInt({player.whatChunk().x, player.whatChunk().z}) << std::endl;
        //std::cout << player.getLocation().x << ", " << player.getLocation().z << std::endl;
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

// ============================
//
//       Managing Chunks
//
// ============================
double GameManager::getPerlinValue(Point2D p)
{
    return png.getPerlinNoise()[mod(p.x, perlinSize)][mod(p.z, perlinSize)];
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
            allSeenChunks[index] = std::make_shared<Chunk>(p, chunkSize, getPerlinValue(p));
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

int mod(int a, int m)
{
    int x = a % m;
    if(x < 0)
    {
        return x + m;
    }
    return x;
}