#pragma once
#include <iostream>
#include "Game.h"

using namespace std;

class Link {
public:
    Game* data;
    Link* next = NULL;
    Link(Game* data);
    void Display();
    Game* GetData();
};