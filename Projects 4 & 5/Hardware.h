//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#ifndef HARDWARE_H
#define HARDWARE_H

#include "Inventory.h"

class Hardware : public Inventory
{
public:
    enum Material_Type { MTunknown, Stainless, Steel, Copper, Bronze };

    Hardware();
    Hardware(string, Date, float, string * = NULL, unsigned = 0);
    Hardware(string, Date, float, Hardware::Material_Type, unsigned);
    ~Hardware();

    void setMaterialType(Hardware::Material_Type);
    void setInStock(unsigned);

    Hardware::Material_Type getMaterialType() const;
    unsigned getInStock() const;

    virtual void display(ostream &) const;

private:
    Hardware::Material_Type _material_type;
    unsigned _inStock;
};

#endif
