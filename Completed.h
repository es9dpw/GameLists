#pragma once
#include "Node.h"

class Completed {
public:
    Node* root;
    Completed();
    Node* Find(string name, int hoursPlayed);
    void DisplayInOrder(Node* localRoot);
    void Insert(Game* data);
};
