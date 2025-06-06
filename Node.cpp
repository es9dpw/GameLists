#include "Node.h"

/*
When initialised sets the data of the node to an existing game object
*/
Node::Node(Game* data) {
    this->data = data; //sets the node's data to an existing game object
    leftChild = nullptr; //sets the left child pointer to a null pointer
    rightChild = nullptr; //sets the right child pointer to a null pointer
}

/*
Displays the game name and play time if there is any
*/
void Node::Display() {
    cout << data->name << ", " << data->hoursPlayed << "h" << endl; //displays the game name and play time
}
