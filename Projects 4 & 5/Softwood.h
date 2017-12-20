//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef SOFTWOOD_H
#define SOFTWOOD_H

#include "Lumber.h"

class Softwood : public Lumber
{
public:
    enum Wood_Type { WTunknown, Pine, Redwood, Fir};

    Softwood();
    Softwood(Softwood::Wood_Type, float);
    Softwood(string, Date, float);
    Softwood(string, Date, float, string*, unsigned);
    Softwood(string, Date, float, Softwood::Wood_Type, float);
    ~Softwood();

    void setUnits(unsigned);
    void setThickness(unsigned);
    void setWoodType(Softwood::Wood_Type);

    unsigned getThickness() const;
    Softwood::Wood_Type getWoodType() const;

    virtual void display(ostream &) const;
    virtual float gross_profit() const;
    virtual unsigned quantity() const;

private:
    Softwood::Wood_Type _wood_type;
    unsigned _thickness;
    unsigned _units;
};

#endif