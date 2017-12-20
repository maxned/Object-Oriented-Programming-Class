//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 1
//  February 10, 2016
//

#include <iostream>
#include <climits>

using namespace std;

unsigned num_digits(unsigned long l);
int nth_digit(unsigned long l, unsigned n);
unsigned long rev_digits(unsigned long l);
bool is_palindrome(unsigned long l);
bool P196(unsigned long l);

int main()
{
    cout << P196(196) << endl;
    return 0;
}

unsigned num_digits(unsigned long l)
{
    if (l < 10) return 1;
    return 1 + num_digits(l/10);
}

int nth_digit(unsigned long l, unsigned n)
{
    int power = 1;
    for (int i = 0; i < n; i++)
    {
        power *= 10;
    }

    if (l/power == 0) return -1;
    return l/power % 10;
}

unsigned long rev_digits(unsigned long l)
{
    int reversedNumber = 0;

    for (int i = num_digits(l); i > 0; i--)
    {
        int power = 1;
        for (int j = 0; j < i - 1; j++)
        {
            power *= 10;
        }

        reversedNumber += nth_digit(l, num_digits(l) - i) * power;
    }

    return reversedNumber;
}

bool is_palindrome(unsigned long l)
{
    return l == rev_digits(l);
}

bool P196(unsigned long l)
{
    unsigned long nextNumber = l + rev_digits(l);
    while (1)
    {
        nextNumber += rev_digits(nextNumber);
        if (is_palindrome(nextNumber)) return true;
    }

    return false;
}
