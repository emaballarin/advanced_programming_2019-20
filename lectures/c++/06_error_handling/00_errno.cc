#include <cmath>
#include <iostream>

int main()
{
    double d = std::sqrt(4);
    std::cout << d << " " << errno << std::endl;

    d = std::sqrt(-4);
    std::cout << d << " " << errno << std::endl;

    /*
    The `errno` is a GLOBAL variable modified by any function/"routine" and that is NOT reset to the defaukt of 0 unless redefined by the user.
    This represents "error propagation".
    */

    return 0;
}
