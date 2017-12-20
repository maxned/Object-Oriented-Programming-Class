//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Softwood.h"

Softwood::Softwood()
:Lumber()
{
    _wood_type = Softwood::WTunknown;
    Lumber::setSurfacingType(Lumber::S4S);
    _thickness = 1;
    _units = 4;
}

Softwood::Softwood(Softwood::Wood_Type type, float cost)
:Lumber()
{
    setWoodType(type);
    set_cost(cost);
    Lumber::setSurfacingType(Lumber::S4S);
    _thickness = 1;
    _units = 4;
}

Softwood::Softwood(string upc, Date purchased, float cost)
:Lumber(upc, purchased, cost, Lumber::S4S, 1)
{
    _wood_type = Softwood::WTunknown;
    _thickness = 1;
    _units = 4;
}

Softwood::Softwood(string upc, Date purchased, float cost, string* suppliers, unsigned num_suppliers)
:Lumber(upc, purchased, cost, suppliers, num_suppliers)
{
    _wood_type = Softwood::WTunknown;
    Lumber::setSurfacingType(Lumber::S4S);
    _thickness = 1;
    _units = 4;
}

Softwood::Softwood(string upc, Date purchased, float cost, Wood_Type t, float wt)
:Lumber(upc, purchased, cost, Lumber::S4S, 1)
{
    _wood_type = t;
    _thickness = 1;
    _units = 4;
}

Softwood::~Softwood()
{

}

void Softwood::setUnits(unsigned units)
{
    _units = units;
}

void Softwood::setThickness(unsigned thickness)
{
    _thickness = thickness;
}

void Softwood::setWoodType(Softwood::Wood_Type type)
{
    _wood_type = type;
}

unsigned Softwood::getThickness() const
{
    return _thickness;
}

Softwood::Wood_Type Softwood::getWoodType() const
{
    return _wood_type;
}

void Softwood::display(ostream &os) const
{
    Lumber::display(os);
    string ht[4] = { "Unknown", "Pine", "Redwood", "Fir" };
    os << "Softwood type: " << ht[_wood_type] << endl
       << "Thickness: " << getThickness() << endl
       << "Units: " << quantity() << endl;
}

float Softwood::gross_profit() const
{
    return (0.05 + _thickness * 0.01) * get_cost() * quantity();
}

unsigned Softwood::quantity() const
{
    return _units;
}
