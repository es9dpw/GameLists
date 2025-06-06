#include "Completed.h"

/*
When the tree is inititalised the tree is set as empty
*/
Completed::Completed() {
    root = nullptr; //sets the root pointer to a null pointer when initialised as no nodes have been added yet
}

/*
Finds a node in the tree
*/
Node* Completed::Find(string name, int hoursPlayed) {
    Node* current = root; //current is set to point to the same node as root
    if (root == nullptr) { //checks if the tree is empty by checking if root points to a node
        return nullptr; //returns a null pointer if the tree in empty
    }
    while (current->data->name != name) { //creates a loop that runs until the name inserted is found in the game object that is in a node.
        if (hoursPlayed > current->data->hoursPlayed) { //checks if the time entered is greater than that in the game object in the node that current points to
            current = current->leftChild; //current is set to point to the same node as the node to the left of current
        }
        else {
            current = current->rightChild; //current is set to point to the same node as the node to the right of current
        }
        if (current == nullptr){ //checks if there are any more nodes left in the branch of the tree
            return nullptr; //returns a null pointer if there are no more nodes in the tree, as the game isn't in the list
        }
    }
    return current; //returns the pointer to the node that contains the game object with the matching name
}

/*
Displays the tree, dsiplaying each node in order of the game object with the most play time to the least
This fucntion uses recursion to display the left most node to the right most node.
It will travel as far down to the left ass possible, before moving to the right.
If it can't move left or right it will move back up and try to move right or move back up again and so on until all nodes are covered.
*/
void Completed::DisplayInOrder(Node* localRoot) {
    if (localRoot != nullptr) { //checks if there are any more nodes left in the tree
        DisplayInOrder(localRoot->leftChild); //Recalls the DisplayInOrder function setting localRoot to the left of the current localRoot
        localRoot->Display(); //calls the display fucntion from the Node class to display the content of the current node
        DisplayInOrder(localRoot->rightChild); //Recalls the DisplayInOrder function setting localRoot to the right of the current localRoot
    }
}

/*
Inserts a new node into the tree
*/
void Completed::Insert(Game* data) {
    Node* newNode = new Node(data); //creates a new pointer newNode which points to a newly created node with the game object enetered
    if (root == nullptr) { //checks if the tree is empty by checking if root points to a node
        root = newNode; //if the tree is empty set the root pointer to point to the same node as newNode, as that node is now the root of the tree
    }
    else {
        Node* current = root; //current is set to point to the same node as root
        Node* parent; //parent pointer is declared
        while (true) {
            parent = current; //parent is set to point to the same node as current
            if (data->hoursPlayed > current->data->hoursPlayed) { //checks if the time played in the entered node is more than in the current node
                current = current->leftChild; //current is set to point to the same node as the node to the left of current
                if (current == nullptr) { //checks if there are any more nodes left in the branch of the tree
                    parent->leftChild = newNode; //sets the node to the left of parent to the node entered
                    return; //returns form the function
                }
            }
            else {
                current = current->rightChild; //current is set to point to the same node as the node to the right of current
                if (current == nullptr) { //checks if there are any more nodes left in the branch of the tree
                    parent->rightChild = newNode; //sets the node to the right of parent to the node entered
                    return; //returns form the function
                }
            }
        }
    }
}