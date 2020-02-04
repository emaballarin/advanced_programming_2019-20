#include <iostream>

#define usl unsigned long int

using namespace std;

int main()
{
    // Acquire primes upper bound...
    usl upbound{};
    cout << "Insert the upper bound of the prime search:" << endl;
    cin >> upbound;

    // Allocate the searchspace
    usl* searchspace = new usl[upbound - 1];  // Index from 0 to upbound-1 -> (i + 2ul)bers from 2 to upbound

    // Fill the searchspace...
    for (usl i{0ul}; i < (upbound - 1ul); i++)
    {
        searchspace[i] = i + 2ul;
    }

    // Use the sieve:
    for (usl i{0ul}; i < (upbound - 1ul); i++)
    {
        if ((i + 2ul) != 0)
        {
            for (usl k{2ul}; k * ((i + 2ul)) <= upbound; k++)
            {
                searchspace[(k * (i + 2ul) - 2)] = 0ul;
            }
        }
    }

    for (usl i{0ul}; i < (upbound - 1ul); i++)
    {
        if (searchspace[i] != 0ul)
        {
            cout << searchspace[i] << endl;
        }
    }
}
