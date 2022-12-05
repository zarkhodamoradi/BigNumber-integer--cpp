#include <iostream>
#include <string>
#ifndef BIGNUMBER_H
#define BIGNUMBER_H
using namespace std;
#pragma once

class BigNumber
{
private:
    friend ostream &operator<<(ostream &, const BigNumber &);
    friend istream &operator>>(istream &input, BigNumber &x);
    int number[100];

public:
    BigNumber();
    BigNumber(const int &);
    BigNumber(const char *);
    ~BigNumber();
    BigNumber operator+(const BigNumber &) const;
    BigNumber operator+(const int &) const;
    BigNumber operator+(const char *) const;
    BigNumber operator-(const BigNumber &) const;
    BigNumber operator-(const int &) const;
    BigNumber operator-(const char *) const;
    BigNumber operator*(const BigNumber &) const;
    BigNumber operator*(const int &) const;
    BigNumber operator*(const char *) const;
    BigNumber operator/(const BigNumber &) const;
    BigNumber operator/(const int &) const;
    BigNumber operator/(const char *) const;
    const BigNumber &operator+=(const BigNumber &);
    const BigNumber &operator+=(const int &);
    const BigNumber &operator+=(const char *);
    const BigNumber &operator-=(const BigNumber &);
    const BigNumber &operator-=(const int &);
    const BigNumber &operator-=(const char *);
    const BigNumber &operator*=(const BigNumber &);
    const BigNumber &operator*=(const int &);
    const BigNumber &operator*=(const char *);
    const BigNumber &operator/=(const BigNumber &);
    const BigNumber &operator/=(const int &);
    const BigNumber &operator/=(const char *);
    const BigNumber operator++(int); // postfix
    const BigNumber &operator++();   // prefix
    const BigNumber operator--(int); // postfix
    const BigNumber &operator--();   // prefix
    bool operator==(const BigNumber &) const;
    bool operator!=(const BigNumber &) const;
    bool operator<(const BigNumber &) const;
    bool operator>(const BigNumber &) const;
    bool operator<=(const BigNumber &) const;
    bool operator>=(const BigNumber &) const;
};
#endif
//////////////////////////////////////////////////////////////////////////////////////////////

/* Constructors  */

// this constructor filled array with 0
BigNumber::BigNumber()
{
    for (int i = 0; i <= 99; i++)
    {
        number[i] = 0;
    }
}
// this costructor recive a integar number and puts it on number array
BigNumber::BigNumber(const int &num)
{
    int count = 99;
    int temp;
    int numcopy = num;

    for (int i = 0; i <= 99; i++)
    {
        number[i] = 0;
    }

    while (numcopy != 0)
    {

        temp = numcopy % 10;
        number[count] = temp;
        numcopy /= 10;

        count--;
    }
}
// this costructor recive a pointer of char and change it to array then a char ,then to string(for size of string) , on the last puts it in the number array
BigNumber::BigNumber(const char *str)
{

    for (int i = 0; i <= 99; i++)
    {
        number[i] = 0;
    }

    char str1[100];
    for (int i = 0; i < 100; i++)
    {
        str1[i] = *(str + i);
    }
    string strOfChar = str1;
    int a = strOfChar.length();

    for (int i = 99, j = a - 1; j >= 0; i--, j--)
    {
        number[i] = *(str + j) - 48;
    }
}
/* Distructor (empty){empty} */
BigNumber::~BigNumber()
{
}

//////////////////////////////////////////////////////////////////////////////////////////////
/* Operator +  */

// operator + for objects with objects
BigNumber BigNumber::operator+(const BigNumber &obj) const
{
    BigNumber empty;

    for (int i = 99; i >= 0; i--)
    {
        empty.number[i] = number[i] + obj.number[i];
    }
    for (int i = 99; i >= 0; i--)
    {

        if (empty.number[i] > 9)
        {
            empty.number[i - 1] += 1;
            empty.number[i] -= 10;
        }
    }

    return empty;
}
// operator + for objects with integer numbers
BigNumber BigNumber::operator+(const int &num) const
{
    int numcpy = num;

    BigNumber obj(numcpy);

    return (*this + obj);
}
// operator + for objects with strings of numbers
BigNumber BigNumber::operator+(const char *str) const
{
    BigNumber obj(str);
    return (*this + obj);
}

//////////////////////////////////////////////////////////////////////////////////////////////
/* Operator -  */

// operator - for objects with objects
BigNumber BigNumber::operator-(const BigNumber &obj) const
{
    BigNumber empty;

    for (int i = 99; i >= 0; i--)
    {
        empty.number[i] = number[i] - obj.number[i];
    }
    for (int i = 99; i >= 0; i--)
    {

        if (empty.number[i] < 0)
        {
            empty.number[i - 1] -= 1;
            empty.number[i] += 10;
        }
    }

    return empty;
}
// operator - for objects with integer numbers
BigNumber BigNumber::operator-(const int &num) const
{
    BigNumber obj(num);
    return (*this - obj);
}
// operator - for objects with strings of numbers
BigNumber BigNumber::operator-(const char *str) const
{
    BigNumber obj(str);
    return (*this - obj);
}
//////////////////////////////////////////////////////////////////////////////////////////////
/* Operator *  */

// operator * for objects with objects
BigNumber BigNumber::operator*(const BigNumber &obj) const
{

    BigNumber empty(obj);
    BigNumber temp;
    BigNumber nothing;

    int i = 99;
    int dah = 1;

    while (empty != nothing)
    {
        temp += (*this);

        if (empty.number[i] == 0)
        {
            i--;
            for (int x = 98; x >= i; x--)
            {
                dah *= 10;
            }

            empty.number[i] = obj.number[i] * (dah);
            dah = 1;
        }
        empty.number[i]--;
    }

    return temp;
}
BigNumber BigNumber::operator*(const int &num) const
{
    BigNumber temp(num);
    return ((*this) * temp);
}
BigNumber BigNumber::operator*(const char *str) const
{
    BigNumber temp(str);
    return ((*this) * temp);
}
BigNumber BigNumber::operator/(const BigNumber &obj) const
{
    BigNumber Empty(*this);
    BigNumber objcpy(obj);

    BigNumber nothings;
    int counter = 0;
    /* (empty != nothing) &&  */
    if (Empty > nothings)
    {
        while ((Empty != nothings))
        {
            Empty -= objcpy;
             counter++;
            if (Empty < objcpy)
            {
                break;
            }
           
        }
    }

    BigNumber temp(counter);
    return temp;
}
BigNumber BigNumber::operator/(const int &num) const
{
    BigNumber temp(num);
    return (*this / temp);
}
BigNumber BigNumber::operator/(const char *str) const
{
    BigNumber temp(str);
    return (*this / temp);
}
//////////////////////////////////////////////////////////////////////////////////////////////
// += & -= Operators
const BigNumber &BigNumber::operator+=(const BigNumber &obj)
{

    return (*this = *this + obj);
}
const BigNumber &BigNumber::operator+=(const int &num)
{
    BigNumber temp(num);
    return (*this = *this + temp);
}
const BigNumber &BigNumber::operator+=(const char *str)
{
    BigNumber temp(str);
    return (*this = *this + temp);
}
const BigNumber &BigNumber::operator-=(const BigNumber &obj)
{

    *this = (*this - obj);
    return (*this);
}
const BigNumber &BigNumber::operator-=(const int &num)
{
    BigNumber temp(num);
    return (*this = *this - temp);
}
const BigNumber &BigNumber::operator-=(const char *str)
{
    BigNumber temp(str);
    return (*this = *this - temp);
}
//////////////////////////////////////////////////////////////////////////////////////////////
//  *= & /= Operators
const BigNumber &BigNumber::operator*=(const BigNumber &obj)
{
    return ((*this) = (*this) * obj);
}
const BigNumber &BigNumber::operator*=(const int &num)
{
    BigNumber temp(num);
    return (*this *= temp);
}
const BigNumber &BigNumber::operator*=(const char *str)
{
    BigNumber temp(str);
    return (*this *= temp);
}
const BigNumber &BigNumber::operator/=(const BigNumber &obj)
{
    return ((*this) = (*this) / obj);
}
const BigNumber &BigNumber::operator/=(const int &num)
{
    BigNumber temp(num);
    return (*this /= temp);
}
const BigNumber &BigNumber::operator/=(const char *str)
{
    BigNumber temp(str);
    return (*this /= temp);
}
//////////////////////////////////////////////////////////////////////////////////////////////
//  ++ & --(postfix and prefix ) Operators
const BigNumber BigNumber::operator++(int)
{
    BigNumber temp = *this;
    *this = *this + 1;
    return temp;
}
const BigNumber &BigNumber::operator++()
{
    return (*this = (*this + 1));
}
const BigNumber BigNumber::operator--(int)
{
    BigNumber temp = *this;
    *this = *this - 1;
    return temp;
}
const BigNumber &BigNumber::operator--()
{
    return (*this = (*this - 1));
}
//////////////////////////////////////////////////////////////////////////////////////////////
//  Comparison Operators
bool BigNumber::operator==(const BigNumber &obj) const
{
    for (int i = 0; i < 100; i++)
    {
        if (number[i] != obj.number[i])
        {
            return false;
        }
    }
    return true;
}
bool BigNumber::operator!=(const BigNumber &obj) const
{
    return !(*this == obj);
}
bool BigNumber::operator<(const BigNumber &obj) const
{
    for (int i = 0; i < 100; i++)
    {
        if ((number[i] == 0 && obj.number[i] == 0))
        {
        }
        /* && (number[i] != 0 || obj.number[i] != 0) */

        else if ((number[i] < obj.number[i]))
        {
            return true;
        }

        else if ((number[i] > obj.number[i]) || (number[i] == obj.number[i]))
        {
            return false;
        }
    }
    return false;
}
bool BigNumber::operator>(const BigNumber &obj) const
{

    for (int i = 0; i < 100; i++)
    {
        if ((number[i] == 0 && obj.number[i] == 0))
        {
        }
        /* && (number[i] != 0 || obj.number[i] != 0) */

        else if ((number[i] > obj.number[i]))
        {
            return true;
        }

        else if ((number[i] < obj.number[i]) || (number[i] == obj.number[i]))
        {
            return false;
        }
    }
    return false;
}
bool BigNumber::operator<=(const BigNumber &obj) const
{
    return !(*this > obj);
}
bool BigNumber::operator>=(const BigNumber &obj) const
{
    return !(*this < obj);
}
//////////////////////////////////////////////////////////////////////////////////////////////
// operator <<
ostream &
operator<<(ostream &out, const BigNumber &obj)
{
    int a;
    int b;
    for (a = 0; a <= 99; a++)
    {
        if (obj.number[a] != 0)
        {
            b = a;
            break;
        }
    }
    if (a == 100)
    {
        out << 0;
    }
else
    for (a = b; a <= 99; a++)
    {
        out << obj.number[a];
    }
    return out;
}
// operator <<
istream &
operator>>(istream &input, BigNumber &obj)
{

    int numcopy;
    cout << "Enter number  : ";
    cin >> numcopy;
    int count = 99;
    int temp;

    for (int i = 0; i <= 99; i++)
    {
        obj.number[i] = 0;
    }

    while (numcopy != 0)
    {

        temp = numcopy % 10;
        obj.number[count] = temp;
        numcopy /= 10;

        count--;
    }

    return input;
}