#pragma once
#include "Link.h"

class ToPlay {
public:
    Link* first;
    ToPlay();
    bool IsEmpty();
    void Insert(Link* newLink);
    void Display();
    Link* Find(string name);
    Link* Delete(string name);
    Link* DeleteFirst();
};
