//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include <iostream>
#include "Inventory.h"

using namespace std;

#ifndef STORE_H
#define STORE_H

#define MAX 20

class Store
{
    Inventory *_store[MAX];
    unsigned _num;

    void newItem();
    void removeItem();
    void displayInventory();
    void displayTotals();

public:
    Store();
    ~Store();

    void Run();
};

#endif
