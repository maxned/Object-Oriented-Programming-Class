//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Hardwood.h"

Hardwood::Hardwood()
:Lumber()
{
    _wood_type = Hardwood::WTunknown;
    Lumber::setSurfacingType(Lumber::Rough);
    _board_feet = 3;
}

Hardwood::Hardwood(Hardwood::Wood_Type type, float cost)
:Lumber()
{
    setWoodType(type);
    set_cost(cost);
    Lumber::setSurfacingType(Lumber::Rough);
    _board_feet = 3;
}

Hardwood::Hardwood(string upc, Date purchased, float cost)
:Lumber(upc, purchased, cost, Lumber::Rough, 1)
{
    _wood_type = Hardwood::WTunknown;
    _board_feet = 3;
}

Hardwood::Hardwood(string upc, Date purchased, float cost, string* suppliers, unsigned num_suppliers)
:Lumber(upc, purchased, cost, suppliers, num_suppliers)
{
    _wood_type = Hardwood::WTunknown;
    Lumber::setSurfacingType(Lumber::Rough);
    _board_feet = 3;
}

Hardwood::Hardwood(string upc, Date purchased, float cost, Wood_Type t, float wt)
:Lumber(upc, purchased, cost, Lumber::Rough, 1)
{
    _wood_type = t;
    _board_feet = 3;
}

Hardwood::~Hardwood()
{

}

void Hardwood::setBoardFeet(unsigned boardFeet)
{
    _board_feet = boardFeet;
}

void Hardwood::setWoodType(Hardwood::Wood_Type type)
{
    _wood_type = type;
}

Hardwood::Wood_Type Hardwood::getWoodType() const
{
    return _wood_type;
}

unsigned Hardwood::getBoardFeet() const
{
    return quantity();
}

void Hardwood::display(ostream &os) const
{
    Lumber::display(os);
    string ht[4] = { "Unknown", "Oak", "Maple", "Birch" };
    os << "Hardwood type: " << ht[_wood_type] << endl
       << "Board feet: " << quantity() << endl;
}

float Hardwood::gross_profit() const
{
    switch (_wood_type) {
        case Oak:
            return 0.15 * get_cost() * quantity();

        case Maple:
            return 0.18 * get_cost() * quantity();

        case Birch:
            return 0.125 * get_cost() * quantity();

        default:
            return 0;
    }
}

unsigned Hardwood::quantity() const
{
    return _board_feet;
}
