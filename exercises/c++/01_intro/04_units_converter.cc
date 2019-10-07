#include <string>       // string
#include <iostream>     // cin, cout, endl
#include <iomanip>      // setprecision

const double mtoin = 39.3701;   // Inches in a meter

int main()
{
    double unitIn{};
    double unitOut{};
    std::string strIn{};
    std::string strOut{};

    while (!((std::cin >> unitIn >> strIn) && (strIn == "in" || strIn == "m")))
    {
        std::cout << "Please, insert meters (m) or inches (in) only..." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }

    if (strIn == "in")
    {
        strOut = "m";
        unitOut = unitIn/mtoin;
    }
    else if (strIn == "m")
    {
        strOut = "in";
        unitOut = unitIn*mtoin;
    }
    else return 1; // Should never happen.

    std::setprecision(10);
    std::cout << unitIn << " " << strIn << " equals to " << unitOut << " " << strOut << std::endl;

    return 0;
}
