#include <string>       // string
#include <iostream>     // cin, cout, endl

// Max. line length
const unsigned int linelen{80};

int main()
{
    // Iterate over lines
    for(std::string linefeed; std::getline(std::cin,linefeed);)
    {
        if (linefeed.length() <= linelen)
        {
            std::cout << linefeed << std::endl;
        }
        else
        {
            unsigned long poscnt{0}; // "unsigned long" as in std::string.length() implementation
            std::string lineout{};

            // Iterate over characters in a line
            while (poscnt < linefeed.length() - linelen)
            {
                // Prevent word breakage (a.k.a. break on previous space)
                unsigned long backsearch{0};
                while (!(linefeed[(poscnt + linelen - backsearch)] == ' '))
                {
                    backsearch++;
                }

                unsigned long lineshift{linelen - backsearch + 1};  // +1 -> Avoid space on newline

                lineout = linefeed.substr(poscnt,lineshift);
                std::cout << lineout << std::endl;
                poscnt += lineshift;
            }
            lineout = linefeed.substr(poscnt);  // Till the end of the string
            std::cout << lineout << std::endl;
        }
    }
}
