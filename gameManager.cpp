#include "gameManager.h"

GameManager::GameManager()
{
    solids.push_back(RecPrism({0, 5, 0}, {0.2,0,1,1},
            3,3, 10, {1,1,1,1}));
}

void GameManager::draw() const
{
    for(const Solid &s : solids)
    {
        s.draw();
    }
}

void GameManager::tick()
{
    
}