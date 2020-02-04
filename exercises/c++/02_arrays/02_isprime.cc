// INCLUDES
#include <cmath>
#include <iostream>

// DEFINES
#define usl unsigned long int

// NAMESPACE DECLARATIONS
using namespace std;

// PROTOTYPES
bool isprime(usl);
usl* replalloc(usl*, size_t, usl);

// FUNCTIONS
bool isprime(usl nin)
{
    for (usl i = 2; i <= floor(sqrt(nin)); i++)
    {
        if ((nin % i) == 0)
        {
            return 0;
        }
    }
    return 1;
}

usl* replalloc(usl* prevvec, size_t prevdim, usl newelem)
{
    usl* retvec = new usl[prevdim + 1];  // Allocate on the heap

    // Copy vector
    for (usl i = 0; i < prevdim; i++)
    {
        retvec[i] = prevvec[i];
    }

    // Deallocate previous vector
    delete[] prevvec;

    // Add element
    retvec[prevdim] = newelem;

    return retvec;
}

// MAIN
int main()
{
    usl* primes = new usl[0];
    usl nrprimes{0};

    for (usl i = 2; i <= 100; i++)
    {
        if (isprime(i))
        {
            primes = replalloc(primes, nrprimes, i);
            nrprimes++;
        }
    }

    for (usl i = 0; i < nrprimes; i++)
    {
        cout << primes[i] << endl;
    }

    delete[] primes;
}
