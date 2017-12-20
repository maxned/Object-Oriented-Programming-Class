//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 2
//  February 24, 2016
//

#include <iostream>
#include <iomanip>
#include "Short.h"

int main()
{
    for (int i = -128; i <= 127; i++)
    {
        cout << setw(4);

        Short s(i);
        s.display();

        cout << " : ";

        s.set_display_type(HEX);
        s.display();

        cout << " : ";

        s.set_display_type(BIN);
        s.display();

        cout << endl;
    }

    Short s(39);
    Short s1(-39);

    s.display();
    cout << endl;

    s.add(s1);
    s.display();
    cout << endl;

    s.add(3);
    s.display();
    cout << endl;

    s1.mult(2);
    s1.display();
    cout << endl;

    s1.set_display_type(HEX);
    s1.display();
    cout << endl;

    s1.set_display_type(BIN);
    s1.display();
    cout << endl;
    
    return 0;
}
