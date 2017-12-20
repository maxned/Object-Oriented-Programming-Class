//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 3
//  March 9, 2016
//

#include "Short.h"

using namespace std;

int main()
{
    Short s0;
    Short s1(10);
    Short s2(15, DEC);
    Short s3(20, DEC);
    Short s4(-25, BIN);
    Short s5("-65");
    Short s6("7Fh");
    Short s7("0000 1010b");
    Short s8("0000 0010b");
    Short s9("0000 0010 ");
    Short s10(s3);

    cout << "s0: " << s0 << endl; // 0
    cout << "s1: " << s1 << endl; // 10
    cout << "s2: " << s2 << endl; // 15
    cout << "s3: " << s3 << endl; // 20
    cout << "s4: " << s4 << endl; // 1110 0111b
    cout << "s5: " << s5 << endl; // -65
    cout << "s6: " << s6 << endl; // 7Fh
    cout << "s7: " << s7 << endl; // 0000 1010b
    cout << "s8: " << s8 << endl; // 0000 0010b
    cout << "s9: " << s9 << endl; // 0
    cout << "s10: " << s10 << endl; // 20

    cout << (s1 = s3) << " " << (s1 += s3) << " " << (s1 -= s3) << " " << (s1 *= s8) << " " << (s1 /= s8) << " " << (s1 %= Short(9)) << endl; // 20 40 20 40 20 2

    s1 = Short(10, DEC);

    cout << (s1 + s2) << " " << (s1 + 5) << " " << (30 + s1) << endl; // 25 15 40
    cout << (s1 - s2) << " " << (s1 - 5) << " " << (30 - s1) << endl; // -5 5 20
    cout << (s1 * s7) << " " << (s1 * 5) << " " << (3 * s1) << endl; // 100 50 30
    cout << (s1 / s2) << " " << (s1 / 5) << " " << (30 / s1) << endl; // 0 2 3
    cout << (s1 % s2) << " " << (s1 % 5) << " " << (30 % s1) << endl; // 10 0 0

    cout << (s1 == s7) << " " << (s1 == 10) << " " << (10 == s1) << endl; // 1 1 1
    cout << (s1 != s7) << " " << (s1 != 10) << " " << (10 != s1) << endl; // 0 0 0
    cout << (s1 > s2) << " " << (s1 > 9) << " " << (11 > s1) << endl; // 0 1 1
    cout << (s1 < s2) << " " << (s1 < 9) << " " << (11 < s1) << endl; // 1 0 0
    cout << (s1 >= s7) << " " << (s1 >= 10) << " " << (10 >= s1) << endl; // 1 1 1
    cout << (s1 <= s7) << " " << (s1 <= 10) << " " << (10 <= s1) << endl; // 1 1 1

    cout << s1++ << " " << s1 << " " << ++s1 << " " << s1 << endl; // 10 11 12 12
    cout << s1-- << " " << s1 << " " << --s1 << " " << s1 << endl; // 12 11 10 10
    cout << -s1 << " " << +s1 << " " << -s1 << endl; // -10 10 -10

    cout << s1.pow(2) << " " << s8.pow(4) << endl; // 100 0001 0000b

    Short s;
    while (1)
    {
        cout << endl << "Enter a number in decimal, hex, or binary format: ";
        cin >> s;
        cout << "You entered: " << s << endl;
        s.set_display_type(DEC);
        cout << "As a decimal: " << s << endl;
    }
    
    return 0;
}
