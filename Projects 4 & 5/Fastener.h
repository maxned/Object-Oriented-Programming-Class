//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef FASTENER_H
#define FASTENER_H

#include "Hardware.h"

class Fastener : public Hardware
{
public:
    enum Fastener_Type { FTunknown, Nails, Screw, Bolt};

    Fastener();
    Fastener(Fastener::Fastener_Type, float);
    Fastener(string, Date, float);
    Fastener(string, Date, float, string*, unsigned);
    Fastener(string, Date, float, Fastener::Fastener_Type, float);
    ~Fastener();

    void setQuantity(unsigned);
    void setFastenerType(Fastener::Fastener_Type);
    void setProfitMargin();

    Fastener::Fastener_Type getFastenerType() const;
    float getProfitMargin() const;

    virtual void display(ostream &) const;
    virtual float gross_profit() const;
    virtual unsigned quantity() const;

private:
    Fastener::Fastener_Type _fastener_type;
    float _profit_margin;
    unsigned _pieces;
};

#endif
