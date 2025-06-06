#pragma once
#include <iostream>
#include "Link.h"

using namespace std;

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