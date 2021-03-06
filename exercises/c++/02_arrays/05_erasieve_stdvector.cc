#include <cmath>
#include <iostream>
#include <vector>

#define usl unsigned long int

using namespace std;

int main()
{
    usl upbound;
    cout << "Insert the upper bound of the prime search:" << endl;
    cin >> upbound;

    vector<usl> searchspace;

    // Populate array
    for (usl i = 2ul; i <= upbound; i++)
    {
        searchspace.push_back(i);
    }

    // Use the sieve with iterators
    for (usl number : searchspace)
    {
        if (number != 0ul)  // Prevent applying the sieve for zero-ed elements
        {
            for (usl k{2}; (number * k) <= upbound; k++)
            {
                (searchspace.at(number * k - 2ul)) = 0ul;
            }
        }
    }

    // Print result.
    for (usl w : searchspace)
    {
        if (w != 0ul)
        {
            cout << w << endl;
        }
    }
}
