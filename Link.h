#pragma once
#include "Game.h"

class Link {
public:
    Game* data;
    Link* next = NULL;
    Link(Game* data);
    void Display();
    Game* GetData();
};
