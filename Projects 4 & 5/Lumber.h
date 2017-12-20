//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef LUMBER_H
#define LUMBER_H

#include "Inventory.h"

class Lumber : public Inventory
{
public:
    enum Surfacing_Type { STunknown, Rough, S2S, S4S };

    Lumber();
    Lumber(string, Date, float, string * = NULL, unsigned = 0);
    Lumber(string, Date, float, Lumber::Surfacing_Type, unsigned);
    ~Lumber();

    void setSurfacingType(Lumber::Surfacing_Type);
    void setInStock(unsigned);

    Lumber::Surfacing_Type getSurfacingType() const;
    unsigned getInStock() const;

    virtual void display(ostream &) const;
    virtual unsigned quantity() const;

private:
    Lumber::Surfacing_Type _surfacing_type;
    unsigned _inStock;
};

#endif
