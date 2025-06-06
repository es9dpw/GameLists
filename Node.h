#pragma once
#include "Game.h"

class Node {
public:
    Node* leftChild;
    Node* rightChild;
    Game* data;
    Node(Game* data);
    void Display();
};
