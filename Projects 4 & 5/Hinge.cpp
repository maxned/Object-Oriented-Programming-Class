//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Hinge.h"

Hinge::Hinge()
:Hardware()
{
    _hinge_type = Hinge::HTunknown;
    Hardware::setMaterialType(Hardware::Copper);
    _pieces = 2;
}

Hinge::Hinge(Hinge::Hinge_Type type, float cost)
:Hardware()
{
    setHingeType(type);
    set_cost(cost);
    Hardware::setMaterialType(Hardware::Copper);
    _pieces = 2;
}

Hinge::Hinge(string upc, Date purchased, float cost)
:Hardware(upc, purchased, cost, Hardware::Copper, 1)
{
    _hinge_type = Hinge::HTunknown;
    _pieces = 2;
}

Hinge::Hinge(string upc, Date purchased, float cost, string* suppliers, unsigned num_suppliers)
:Hardware(upc, purchased, cost, suppliers, num_suppliers)
{
    _hinge_type = Hinge::HTunknown;
    Hardware::setMaterialType(Hardware::Copper);
    _pieces = 2;
}

Hinge::Hinge(string upc, Date purchased, float cost, Hinge_Type ht, float wt)
:Hardware(upc, purchased, cost, Hardware::Copper, 1)
{
    _hinge_type = ht;
    _pieces = 2;
}

Hinge::~Hinge()
{

}

void Hinge::setQuantity(unsigned quantity)
{
    _pieces = quantity;
}

void Hinge::setHingeType(Hinge::Hinge_Type type)
{
    _hinge_type = type;
}

Hinge::Hinge_Type Hinge::getHingeType() const
{
    return _hinge_type;
}

void Hinge::display(ostream &os) const
{
    Hardware::display(os);
    string ht[4] = { "Unknown", "Butt", "Overlay", "Offset" };
    os << "Hinge type: " << ht[_hinge_type] << endl
       << "Pieces: " << quantity() << endl;
}

float Hinge::gross_profit() const
{
    return 0.125 * get_cost() * quantity();
}

unsigned Hinge::quantity() const
{
    return _pieces;
}
