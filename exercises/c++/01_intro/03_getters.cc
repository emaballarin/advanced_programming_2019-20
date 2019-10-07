#include <iostream>
#include <cmath>
#include <string>

/*
 * Relatively-safe getters for int and double types. *
 *
 * Safer approaches should require string-based manipulation and/or variable-epsilon comparisons.
 */

// FUNCTION PROTOTYPES (not *that* useful in this case...)
static bool epsEqual(double lhs, double rhs, double epsilon);
static double getDouble();
static int getInt();


// Simple comparison tool (up to double precision)
static bool epsEqual(double lhs, double rhs, double epsilon)
{
    return (std::abs(lhs - rhs) <= epsilon);
}


static double getDouble()
{
    double charfeed{};
    while(!(std::cin >> charfeed))
    {
        std::cout << "Please, retry..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

    return charfeed;
}



static int getInt()
{
    double charfeed{};

    // 1st condition: catch char/literal input;
    // 2nd condition: check if the input is integer;
    while(!((std::cin >> charfeed) && (epsEqual(charfeed,static_cast<int>(charfeed),1e-16))))
    {
        std::cout << "Please, retry..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

    return static_cast<int>(charfeed);
}


int main()
{
    int testint = getInt();
    double testdouble = getDouble();

    // Suppress unused variable warning
    static_cast<void>(testint);
    static_cast<void>(testdouble);
}
