//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef HINGE_H
#define HINGE_H

#include "Hardware.h"

class Hinge : public Hardware
{
public:
    enum Hinge_Type { HTunknown, Butt, Overlay, Offset};

    Hinge();
    Hinge(Hinge::Hinge_Type, float);
    Hinge(string, Date, float);
    Hinge(string, Date, float, string*, unsigned);
    Hinge(string, Date, float, Hinge::Hinge_Type, float);
    ~Hinge();

    void setQuantity(unsigned);
    void setHingeType(Hinge::Hinge_Type);

    Hinge::Hinge_Type getHingeType() const;

    virtual void display(ostream &) const;
    virtual float gross_profit() const;
    virtual unsigned quantity() const;

private:
    Hinge::Hinge_Type _hinge_type;
    unsigned _pieces;
};

#endif
