//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef HARDWOOD_H
#define HARDWOOD_H

#include "Lumber.h"

class Hardwood : public Lumber
{
public:
    enum Wood_Type { WTunknown, Oak, Maple, Birch};

    Hardwood();
    Hardwood(Hardwood::Wood_Type, float);
    Hardwood(string, Date, float);
    Hardwood(string, Date, float, string*, unsigned);
    Hardwood(string, Date, float, Hardwood::Wood_Type, float);
    ~Hardwood();

    void setBoardFeet(unsigned);
    void setWoodType(Hardwood::Wood_Type);

    Hardwood::Wood_Type getWoodType() const;
    unsigned getBoardFeet() const;

    virtual void display(ostream &) const;
    virtual float gross_profit() const;
    virtual unsigned quantity() const;

private:
    Hardwood::Wood_Type _wood_type;
    unsigned _board_feet;
};

#endif