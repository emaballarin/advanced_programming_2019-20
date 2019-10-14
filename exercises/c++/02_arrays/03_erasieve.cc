#include <iostream>

#define usl unsigned long int

using namespace std;

int main()
{
    usl ubprimes{};

    cout << "Insert a number (primes upper bound)..." << endl;
    cin >> ubprimes;

    usl *searchspace = new usl[ubprimes - 1ul];

    // Fill with integers upto upper bound.
    for (usl i = 2; i < ubprimes; i++) { searchspace[i - 2ul] = i; }

    // Use the sieve
    for (usl j = 0; j < ubprimes - 1ul; j++)
    {
        if (searchspace[j] == 0) { continue; }
        else
        {
            for (usl k = 2;
                 k <= (static_cast<unsigned long>((ubprimes) / static_cast<unsigned long>((j))) && k <= ubprimes - 1ul);
                 k++)
            { searchspace[k * searchspace[j] - 2ul] = 0; }
        }
    }

    // Print the result
    for (usl j = 0; j < ubprimes - 1ul; j++)
    {
        if (searchspace[j] != 0) { cout << searchspace[j] << " "; }
    }
    cout << endl;

    // Cleanup
    delete[] searchspace;
}
