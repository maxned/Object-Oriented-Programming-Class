//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Lumber.h"

Lumber::Lumber()
:Inventory()
{
    _surfacing_type = Lumber::STunknown;
}

Lumber::Lumber(string upc, Date purchased, float cost, string *suppliers, unsigned numSuppliers)
:Inventory(upc, purchased, cost, suppliers, numSuppliers)
{
    _surfacing_type = Lumber::STunknown;
}

Lumber::Lumber(string upc, Date purchased, float cost, Lumber::Surfacing_Type type, unsigned inStock)
:Inventory(upc, purchased, cost)
{
    _surfacing_type = type;
    _inStock = inStock;
}

Lumber::~Lumber()
{

}

void Lumber::setSurfacingType(Lumber::Surfacing_Type type)
{
    _surfacing_type = type;
}

void Lumber::setInStock(unsigned inStock)
{
    _inStock = inStock;
}

Lumber::Surfacing_Type Lumber::getSurfacingType() const
{
    return _surfacing_type;
}

unsigned Lumber::getInStock() const
{
    return _inStock;
}

void Lumber::display(ostream &os) const
{
    Inventory::display(os);

    string type[4] = { "Unknown", "Rough", "S2S", "S4S" };
    os << "Material: " << type[_surfacing_type] << endl;
}

unsigned Lumber::quantity() const
{
    return _inStock;
}
