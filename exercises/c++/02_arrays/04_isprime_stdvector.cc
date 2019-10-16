#include <cmath>
#include <iostream>
#include <vector>

#define usl unsigned long int

using namespace std;

bool isprime(usl);

bool isprime(usl nin)
{
    for (usl i = 2ul; i <= floor(sqrt(nin)); i++)
    {
        if ((nin % i) == 0) { return 0; }
    }
    return 1;
}

int main()
{
    vector<usl> searchspace;

    // Populate array checking for primality on the fly...
    for (usl i = 2ul; i <= 100ul; i++)
    {
        if (isprime(i)) { searchspace.push_back(i); }
    }

    // Print result.
    for (usl k : searchspace) { cout << k << endl; }
}
