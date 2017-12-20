//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 2
//  February 24, 2016
//

#ifndef _SHORT_H_
#define _SHORT_H_

#include <iostream>

using namespace std;

enum display_type { DEC, BIN, HEX };

class Short
{
    signed char _n;
    display_type _dt;
    void _display_BIN() const;
    void _display_HEX() const;

public:
    Short();
    Short(signed char, display_type = DEC);
    void add(const Short&);
    void sub(const Short&);
    void mult(const Short&);
    void div(const Short&);
    void display() const;
    void set_display_type(display_type);
};

#endif
