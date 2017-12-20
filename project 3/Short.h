//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 3
//  March 9, 2016
//

#ifndef _SHORT_H_
#define _SHORT_H_

#include <iostream>

using namespace std;

enum display_type { DEC, BIN, HEX, ERROR };

class Short
{
    signed char _n;
    display_type _dt;
    void _display_BIN(ostream&) const;
    void _display_HEX(ostream&) const;

public:

    Short();
    Short(signed char, display_type = DEC);
    Short(const char *);
    Short(const Short&);

    // Immediate operators
    Short& operator= (const Short&);
    Short& operator+= (const Short&);
    Short& operator-= (const Short&);
    Short& operator*= (const Short&);
    Short& operator/= (const Short&);
    Short& operator%= (const Short&);

    // I/O functions
    friend ostream& operator<< (ostream&, const Short&);
    friend istream& operator>> (istream&, Short&);

    // Arithmetic operators
    Short operator+ (const Short&) const;
    Short operator+ (signed char) const;
    friend Short operator+ (signed char, const Short&);
    Short operator- (const Short&) const;
    Short operator- (signed char) const;
    friend Short operator- (signed char, const Short&);
    Short operator* (const Short&) const;
    Short operator* (signed char) const;
    friend Short operator* (signed char, const Short&);
    Short operator/ (const Short&) const;
    Short operator/ (signed char) const;
    friend Short operator/ (signed char, const Short&);
    Short operator% (const Short&) const;
    Short operator% (signed char) const;
    friend Short operator% (signed char, const Short&);

    // Comparison operators
    bool operator== (const Short&) const;
    bool operator== (signed char) const;
    friend bool operator== (signed char, const Short&);
    bool operator!= (const Short&) const;
    bool operator!= (signed char) const;
    friend bool operator!= (signed char, const Short&);
    bool operator> (const Short&) const;
    bool operator> (signed char) const;
    friend bool operator> (signed char, const Short&);
    bool operator< (const Short&) const;
    bool operator< (signed char) const;
    friend bool operator< (signed char, const Short&);
    bool operator>= (const Short&) const;
    bool operator>= (signed char) const;
    friend bool operator>= (char, const Short&);
    bool operator<= (const Short&) const;
    bool operator<= (signed char) const;
    friend bool operator<= (signed char, const Short&);

    // Unary operators
    Short operator++ (int); // post
    Short operator-- (int); // post
    Short& operator++ (); // pre
    Short& operator-- (); // pre
    Short operator- () const;
    Short operator+ () const;

    Short pow(unsigned exp) const;

    void set_display_type(display_type);
};

#endif
