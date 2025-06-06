#pragma once
#include "Game.h"

class Dropped {
public:
    Game** data;
    int size;
    void Display();
    int HashFunction(string key);
    Dropped(int size);
    void Insert(Game* item);
    Game* Find(string key);
    Game* Delete(string key);
};
