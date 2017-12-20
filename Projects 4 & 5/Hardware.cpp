//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Hardware.h"

Hardware::Hardware()
:Inventory()
{
    _material_type = Hardware::MTunknown;
}

Hardware::Hardware(string upc, Date purchased, float cost, string *suppliers, unsigned numSuppliers)
:Inventory(upc, purchased, cost, suppliers, numSuppliers)
{
    _material_type = Hardware::MTunknown;
}

Hardware::Hardware(string upc, Date purchased, float cost, Hardware::Material_Type type, unsigned inStock)
:Inventory(upc, purchased, cost)
{
    _material_type = type;
    _inStock = inStock;
}

Hardware::~Hardware()
{

}

void Hardware::setMaterialType(Hardware::Material_Type type)
{
    _material_type = type;
}

void Hardware::setInStock(unsigned inStock)
{
    _inStock = inStock;
}

Hardware::Material_Type Hardware::getMaterialType() const
{
    return _material_type;
}

unsigned Hardware::getInStock() const
{
    return _inStock;
}

void Hardware::display(ostream &os) const
{
    Inventory::display(os);

    string type[5] = { "Unknown", "Stainless", "Steel", "Copper", "Bronze" };
    os << "Material: " << type[_material_type] << endl;
}
