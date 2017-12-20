//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Fastener.h"

Fastener::Fastener()
:Hardware()
{
    setFastenerType(FTunknown);
    Hardware::setMaterialType(Hardware::Steel);
    _pieces = 1;
}

Fastener::Fastener(Fastener::Fastener_Type type, float cost)
:Hardware()
{
    setFastenerType(type);
    set_cost(cost);
    Hardware::setMaterialType(Hardware::Steel);
    _pieces = 1;
}

Fastener::Fastener(string upc, Date purchased, float cost)
:Hardware(upc, purchased, cost, Hardware::Steel, 1)
{
    setFastenerType(FTunknown);
    _pieces = 1;
}

Fastener::Fastener(string upc, Date purchased, float cost, string* suppliers, unsigned num_suppliers)
:Hardware(upc, purchased, cost, suppliers, num_suppliers)
{
    setFastenerType(FTunknown);
    Hardware::setMaterialType(Hardware::Steel);
    _pieces = 1;
}

Fastener::Fastener(string upc, Date purchased, float cost, Fastener_Type ft, float wt)
:Hardware(upc, purchased, cost, Hardware::Steel, 1)
{
    setFastenerType(ft);
    _pieces = 1;
}

Fastener::~Fastener()
{

}

void Fastener::setQuantity(unsigned quantity)
{
    _pieces = quantity;
}

void Fastener::setFastenerType(Fastener::Fastener_Type type)
{
    _fastener_type = type;
    setProfitMargin();
}

void Fastener::setProfitMargin()
{
    switch (_fastener_type) {
        case Nails:
            _profit_margin = 0.05;
            break;

        case Screw:
            _profit_margin = 0.075;
            break;

        case Bolt:
            _profit_margin = 0.1;
            break;

        default:
            _profit_margin = 0;
            break;
    }
}

Fastener::Fastener_Type Fastener::getFastenerType() const
{
    return _fastener_type;
}

float Fastener::getProfitMargin() const
{
    return _profit_margin;
}

void Fastener::display(ostream &os) const
{
    Hardware::display(os);
    string ft[4] = { "Unknown", "Nails", "Screw", "Bolt" };
    os << "Fastener type: " << ft[_fastener_type] << endl
       << "Pieces: " << quantity() << endl
       << "Profit Margin: " << getProfitMargin() << endl;
}

float Fastener::gross_profit() const
{
    return _profit_margin * get_cost() * quantity();
}

unsigned Fastener::quantity() const
{
    return _pieces;
}
