//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 2
//  February 24, 2016
//

#include "Short.h"

Short::Short()
{
    _n = 0;
    _dt = DEC;
}

Short::Short(signed char c, display_type type)
{
    _n = c;
    _dt = type;
}

void Short::add(const Short &s)
{
    _n += s._n;
}

void Short::sub(const Short &s)
{
    _n -= s._n;
}

void Short::mult(const Short &s)
{
    _n *= s._n;
}

void Short::div(const Short &s)
{
    _n /= s._n;
}

void Short::display() const
{
    switch (_dt)
    {
        case DEC: cout << (int)_n; break;
        case BIN: _display_BIN(); break;
        case HEX: _display_HEX(); break;
    }
}

void Short::_display_BIN() const
{
    int n = _n;
    if (n < 0) n += 256;

    int binary[8] = { 0 };
    int i = 0;
    while (n)
    {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }

    for (int j = 7; j >= 0; j--)
    {
        if (j == 3) cout << " ";
        cout << binary[j];
    }

    cout << "b";
}

void Short::_display_HEX() const
{
    int n = _n;
    if (n < 0) n += 256;

    char hex[3] = { 0 };
    int i = 0;
    while (n)
    {
        hex[i++] = n % 16 + ((n % 16 > 9) ? '7' : '0');
        n /= 16;
    }

    for (int j = 1; j >= 0; j--)
    {
        cout << (hex[j] == '\0' ? '0' : hex[j]);
    }

    cout << "h";
}

void Short::set_display_type(display_type type)
{
    _dt = type;
}
