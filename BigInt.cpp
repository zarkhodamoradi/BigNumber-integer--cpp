#include <iostream>
#include "BigNumber.h"
using namespace std;

int main()
{
    BigNumber a("999999999999999999999");
    BigNumber b(5);
    BigNumber c;
    BigNumber d("999999999999999999999");

    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    c += a * 2 - b;
    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    c -= a / d;
    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    c -= a;
    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    c = b--;
    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    c = --b;
    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << c << endl
         << endl;
    if (a == b)
        cout << "equal\n";
    else
        cout << "Not equal\n";
}
