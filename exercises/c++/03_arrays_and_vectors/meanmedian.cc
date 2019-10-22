// INCLUDES
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// DEFINES
#define usl unsigned long int

// NS DECLARATIONS
using namespace std;

// PROTOTYPES
double mean_stdvec(vector<double>);
double median_stdvec(vector<double>);

// IMPLEMENTATIONS
double mean_stdvec(vector<double> invector)
{
    double mean{};

    // Compute sum of elements
    double vecsum{};
    for (double number : invector) { vecsum += number; }

    // Actually Compute mean
    mean = (vecsum / static_cast<double>(invector.size()));

    return mean;
}

double median_stdvec(vector<double> invector)
{
    double median{};
    vector<double> copiedvector{invector};

    // Sort copied vector
    sort(copiedvector.begin(), copiedvector.end());

    if (invector.size() % 2ul == 0)  // Even
    {
        // The average of the two elements around the (non-integer) position at the half of the sorted vector.
        median = ((copiedvector.at(static_cast<size_t>(floor(static_cast<double>(invector.size()) / 2)))
                   + copiedvector.at(static_cast<size_t>(ceil(static_cast<double>(invector.size()) / 2))))
                  / 2);

        return median;
    }

    else if (invector.size() % 2ul == 1)  // Odd
    {
        // The element at the (integer) position at the half of the sorted vector
        median = copiedvector.at(static_cast<size_t>(invector.size() / 2));

        return median;
    }
    else  // Something very wrong!
    {
        throw "The number of elements passed to the array is neither EVEN nor ODD! You just discovered new "
              "mathematics! ;-)";
    }
}


int main()
{
    std::string linefeed{};        // Input parsing variable (`stod` to be called upon)
    vector<double> accumulator{};  // Number store

    // Read input line by line + Count lines;
    for (std::string linefeed; std::getline(std::cin, linefeed);)  // Acceptable variable shadowing (-Wshadow)
    { accumulator.push_back(stod(linefeed)); }

    // Compute the mean and the median

    double mean{mean_stdvec(accumulator)};
    double median{median_stdvec(accumulator)};

    cout << "\n"
         << "SUMMARY STATISTICS:"
         << "\n\n"
         << "Number of elements: " << accumulator.size() << " \n"
         << "Mean: " << mean << " \n"
         << "Median: " << median << " \n"
         << "\n"
         << endl;
}
