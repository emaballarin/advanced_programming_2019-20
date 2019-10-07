#include <string>
#include <iostream>

int main()
{
    std::string previous_line{};
    std::string linefeed{};
    unsigned int wordcnt{1};

    std::getline(std::cin, linefeed);
    previous_line = linefeed;

    for(std::string linefeed; std::getline(std::cin,linefeed);) // Acceptable variable shadowing (-Wshadow)
    {
        if (previous_line == linefeed)
        {
            wordcnt++;
        }
        else
        {
            std::cout << "     " << wordcnt << " "<< previous_line << std::endl;    // 5 spaces is hardcoded from the original
            wordcnt = 1;
        }

        previous_line = linefeed;
    }

    // Flush buffered word/count
    std::cout << "     " << wordcnt << " "<< previous_line << std::endl;    // 5 spaces is hardcoded from the original
}
