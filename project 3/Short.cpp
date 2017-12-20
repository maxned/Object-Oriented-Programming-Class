//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 3
//  March 9, 2016
//

#include "Short.h"

display_type type(const char *);
bool isDecimal(const char *);
bool isHex(const char *);
bool isBinary(const char *);
bool isSign(const char);
bool isDecimalDigit(const char);
bool isHexDigit(const char);
bool isHexLetter(const char);
bool isBinaryDigit(const char);
signed char decimalToSignedChar(const char *);
signed char hexToSignedChar(const char *);
signed char binaryToSignedChar(const char *);
int pow(int number, unsigned exp);

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

Short::Short(const char *c)
{
    switch (type(c))
    {
        case DEC:
            _n = decimalToSignedChar(c);
            _dt = DEC;
            break;

        case BIN:
            _n = binaryToSignedChar(c);
            _dt = BIN;
            break;

        case HEX:
            _n = hexToSignedChar(c);
            _dt = HEX;
            break;

        case ERROR:
            _n = 0;
            _dt = DEC;
            break;
    }
}

Short::Short(const Short &s)
{
    _n = s._n;
    _dt = s._dt;
}

// Immediate operators

Short& Short::operator= (const Short &s)
{
    if (this == &s) return *this;
    _n = s._n;
    _dt = s._dt;
    return *this;
}

Short& Short::operator+= (const Short &s)
{
    _n += s._n;
    return *this;
}

Short& Short::operator-= (const Short &s)
{
    _n -= s._n;
    return *this;
}

Short& Short::operator*= (const Short &s)
{
    _n *= s._n;
    return *this;
}

Short& Short::operator/= (const Short &s)
{
    _n /= s._n;
    return *this;
}

Short& Short::operator%= (const Short &s)
{
    _n %= s._n;
    return *this;
}

// I/O functions

ostream& operator<< (ostream &os, const Short &s)
{
    switch (s._dt)
    {
        case DEC: os << int(s._n); break;
        case BIN: s._display_BIN(os); break;
        case HEX: s._display_HEX(os); break;
        default: os << "Error"; break;
    }

    return os;
}

istream& operator>> (istream &is, Short &s)
{
    char input[11];
    is.getline(input, 11);
    s = Short(input);
    return is;
}

// Arithmetic operators

Short Short::operator+ (const Short &s) const
{
    Short temp(*this);
    temp += s;
    return temp;
}

Short Short::operator+ (signed char c) const
{
    Short temp(*this);
    temp += Short(c);
    return temp;
}

Short operator+ (signed char c, const Short &s)
{
    return Short(c) += s;
}

Short Short::operator- (const Short &s) const
{
    Short temp(*this);
    temp -= s;
    return temp;
}

Short Short::operator- (signed char c) const
{
    Short temp(*this);
    temp -= Short(c);
    return temp;
}

Short operator- (signed char c, const Short &s)
{
    return Short(c) -= s;
}

Short Short::operator* (const Short &s) const
{
    Short temp(*this);
    temp *= s;
    return temp;
}

Short Short::operator* (signed char c) const
{
    Short temp(*this);
    temp *= Short(c);
    return temp;
}

Short operator* (signed char c, const Short &s)
{
    return Short(c) *= s;
}

Short Short::operator/ (const Short &s) const
{
    Short temp(*this);
    temp /= s;
    return temp;
}

Short Short::operator/ (signed char c) const
{
    Short temp(*this);
    temp /= Short(c);
    return temp;
}

Short operator/ (signed char c, const Short &s)
{
    return Short(c) /= s;
}

Short Short::operator% (const Short &s) const
{
    Short temp(*this);
    temp %= s;
    return temp;
}

Short Short::operator% (signed char c) const
{
    Short temp(*this);
    temp %= Short(c);
    return temp;
}

Short operator% (signed char c, const Short &s)
{
    return Short(c) %= s;
}

// Comparison operators

bool Short::operator== (const Short &s) const
{
    return _n == s._n;
}

bool Short::operator== (signed char c) const
{
    return *this == Short(c);
}

bool operator== (signed char c, const Short &s)
{
    return Short(c) == s;
}

bool Short::operator!= (const Short &s) const
{
    return _n != s._n;
}

bool Short::operator!= (signed char c) const
{
    return *this != Short(c);
}

bool operator!= (signed char c, const Short &s)
{
    return Short(c) != s;
}

bool Short::operator> (const Short &s) const
{
    return _n > s._n;
}

bool Short::operator> (signed char c) const
{
    return *this > Short(c);
}

bool operator> (signed char c, const Short &s)
{
    return Short(c) > s;
}

bool Short::operator< (const Short &s) const
{
    return _n < s._n;
}

bool Short::operator< (signed char c) const
{
    return *this < Short(c);
}

bool operator< (signed char c, const Short &s)
{
    return Short(c) < s;
}

bool Short::operator>= (const Short &s) const
{
    return _n >= s._n;
}

bool Short::operator>= (signed char c) const
{
    return *this >= Short(c);
}

bool operator>= (char c, const Short &s)
{
    return Short(c) >= s;
}

bool Short::operator<= (const Short &s) const
{
    return _n <= s._n;
}

bool Short::operator<= (signed char c) const
{
    return *this <= Short(c);
}

bool operator<= (signed char c, const Short &s)
{
    return Short(c) <= s;
}

// Unary operators

Short Short::operator++ (int i) // post
{
    Short old(*this);
    ++_n;
    return old;
}

Short Short::operator-- (int i) // post
{
    Short old(*this);
    --_n;
    return old;
}

Short& Short::operator++ () // pre
{
    ++_n;
    return *this;
}

Short& Short::operator-- () // pre
{
    --_n;
    return *this;
}

Short Short::operator- () const
{
    Short temp(*this);
    temp._n = ~temp._n + 1;
    return temp;
}

Short Short::operator+ () const
{
    return *this;
}

Short Short::pow(unsigned exp) const
{
    if (exp == 0) return Short(1);
    if (exp == 1) return Short(*this);

    Short temp(*this);
    temp._n *= temp.pow(exp - 1)._n;
    return temp;
}

void Short::set_display_type(display_type type)
{
    _dt = type;
}

display_type type(const char *c)
{
    if (isDecimal(c)) return DEC;
    if (isBinary(c)) return BIN;
    if (isHex(c)) return HEX;
    return ERROR;
}

void Short::_display_HEX(ostream &os) const
{
    int n = _n;
    if (n < 0) n += 256;

    char hex[3] = { 0 };
    int i = 0;
    while (n)
    {
        hex[i++] = n % 16 + ((n % 16 > 9) ? '7' : '0'); // skips a few characters between the numbers and A-F
        n /= 16;
    }

    for (int j = 1; j >= 0; j--)
    {
        os << (hex[j] == '\0' ? '0' : hex[j]);
    }

    os << "h";
}

void Short::_display_BIN(ostream &os) const
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
        if (j == 3) os << " ";
        os << binary[j];
    }

    os << "b";
}

bool isDecimal(const char *c)
{
    if (!isSign(c[0]) && !isDecimalDigit(c[0])) return false;

    int i;
    for (i = 0; i < 5; i++)
    {
        if (c[i] == '\0') break;
    }

    if (i > 4 || (i == 4 && !isSign(c[0])) || (i == 1 && isSign(c[0]))) return false;

    int j = 0;
    if (isSign(c[0])) j = 1;

    for (; j < i; j++)
    {
        if (!isDecimalDigit(c[j])) return false;
    }

    return true;
}

bool isHex(const char *c)
{
    if (c[2] != 'h') return false;
    if (!isHexDigit(c[0]) || !isHexDigit(c[1])) return false;
    if (c[3] != '\0') return false;
    return true;
}

bool isBinary(const char *c)
{
    if (c[9] != 'b') return false;

    for (int i = 0; i < 9; i++)
    {
        if ((i != 4 && !isBinaryDigit(c[i])) || (i == 4 && c[i] != ' ')) return false;
    }

    return true;
}

bool isSign(const char c)
{
    if (c == '+' || c == '-') return true;
    return false;
}

bool isDecimalDigit(const char c)
{
    char possibleDigits[11] = "0123456789";

    for (int i = 0; i < 10; i++)
    {
        if (c == possibleDigits[i]) return true;
    }

    return false;
}

bool isHexDigit(const char c)
{
    char possibleDigits[17] = "0123456789ABCDEF";

    for (int i = 0; i < 16; i++)
    {
        if (c == possibleDigits[i]) return true;
    }

    return false;
}

bool isHexLetter(const char c)
{
    char possibleDigits[7] = "ABCDEF";

    for (int i = 0; i < 6; i++)
    {
        if (c == possibleDigits[i]) return true;
    }

    return false;
}

bool isBinaryDigit(const char c)
{
    if (c == '0' || c == '1') return true;
    return false;
}

signed char decimalToSignedChar(const char *c)
{
    int j = 0;
    if (isSign(c[0])) j = 1;

    int number = 0;
    for (int i = j; c[i] != '\0'; i++)
    {
        number = number*10 + c[i] - '0';
    }

    if (c[0] == '-') number = ~number + 1;

    return number;
}

signed char hexToSignedChar(const char *c)
{
    int number = 0;
    for (int i = 0; i < 2; i++)
    {
        number = number*16 + c[i] - (isHexLetter(c[i]) ? '7' : '0');
    }

    return number;
}

signed char binaryToSignedChar(const char *c)
{
    int number = 0;

    for (int i = 0; i < 9; i++)
    {
        if (i != 4)
        {
            if (c[i] == '1')
            {
                number += pow(2, 8 - (i < 4 ? i + 1 : i));
            }
        }
    }

    return number;
}

int pow(int number, unsigned exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return number;
    return number *= pow(number, exp - 1);
}
