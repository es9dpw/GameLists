#include "ToPlay.h"

/*
When the linked list is inititalised the linked list is set as empty
*/
ToPlay::ToPlay() {
    first = nullptr; //sets the first pointer to a null pointer when initialised as no links have been added yet
}

/*
Checks if the linked list is empty
*/
bool ToPlay::IsEmpty() {
    return (first == nullptr); //checks if first is a nullptr. If it is then the linked list is empty so returns true, otherwise returns false
}

/*
Inserts a new link into the linked list
*/
void ToPlay::Insert(Link* newLink) {
    newLink->next = first; //the new links next pointer is set to point at the link first points to
    first = newLink; //first is set to point to the new link just inserted, as it is now first in the linked list
}

/*
Displays the linked list
*/
void ToPlay::Display() {
    Link* current = first; //current is set to point to the same link as first
    while (current != nullptr) { //checks that current is not a null pointer, meaning that are are still more links to display
        current->Display(); //calls the display fucntion from the Link class to display the content of the current link
        current = current->next; //set the current pointer to point to the next link in the linked list
    }
}

/*
Finds a link in the linked list
*/
Link* ToPlay::Find(string name) {
    if (IsEmpty() == true) { //calls the IsEmpty function to check if the linked list is empty
        return nullptr; //returns a null pointer if the linked list in empty
    }
    Link* current = first; //current is set to point to the same link as first
    while (current->data->name != name) { //creates a loop that runs until the name inserted is found in the game object that is in a link.
        if (current->next == nullptr) { //checks if there are any more links left in the linked list
            return nullptr; //returns a null pointer if there are no more links in the linked list, as the game isn't in the list
        }
        else {
            current = current->next; //if there are more links then set the current pointer to point to the next link in the linked list
        }
    }
    return current; //returns the pointer to the link that contains the game object with the matching name
}

/*
Deletes a link in the linked list
*/
Link* ToPlay::Delete(string name) {
    if (IsEmpty() == true) { //calls the IsEmpty function to check if the linked list is empty
        return nullptr; //returns a null pointer if the linked list in empty
    }
    Link* current = first; //current is set to point to the same link as first
    Link* previous = first; //previous is set to point to the same link as first
    while (current->data->name != name) { //creates a loop that runs until the name inserted is found in the game object that is in a link.
        if (current->next == nullptr) { //checks if there are any more links left in the linkedlist
            return nullptr; //returns a null pointer if there are no more links in the linked list, as the game isn't in the list
        }
        else {
            previous = current; //if there are more links then set the previous pointer to point to the same link as current
            current = current->next; //if there are more links then set the current pointer to point to the next link in the linked list
        }
    }
    if (current == first) { //checks if current points to the same link as first
        first = first->next; //if current points to the same link as first, then first is set to point to the next link after the link first currently points to
    }
    else {
        previous->next = current->next; //if current doesn't point to the same link as first, then previous is set to point to the link that current points to, leaving nothing in the linked list point to the link current is pointing to, removing it from the linked list
    }
    return current; //returns the pointer to the link that was deleted
}

/*
Deletes the first link in the linked list
*/
Link* ToPlay::DeleteFirst() {
    if (IsEmpty() == true) { //calls the IsEmpty function to check if the linked list is empty
        return nullptr; //returns a null pointer if the linked list in empty
    }
    Link* temp = first; //creates a temporary pointer to point to the same link as first
    first = first->next; //first is set to point to the next link after the link first currently points to
    return temp; //returns the pointer to the link that was deleted
}