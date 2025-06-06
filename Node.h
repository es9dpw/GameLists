#pragma once
#include "Game.h"

using namespace std;

class Node {
public:
    Node* leftChild;
    Node* rightChild;
    Game* data;
    Node(Game* data);
    void Display();
};
