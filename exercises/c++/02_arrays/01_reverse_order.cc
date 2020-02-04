#include <iostream>
using namespace std;


template<typename TName>
TName* valloc(size_t vdim);

template<typename TName>
void revorder(TName inarray, size_t vdim);


template<typename TName>
TName* valloc(size_t vdim)
{
    return (new TName[vdim]);
}

template<typename TName>
void printrev(TName* inarray, size_t vdim)
{
    for (size_t elem = vdim; 1; elem--)
    {
        cout << inarray[elem - 1] << " ";
        if (elem == 1)
            break;
    }
    cout << endl;
}

int main()
{
    size_t getvdim;

    cout << "Insert the dimension if the array... " << endl;
    cin >> getvdim;

    int* intarray = valloc<int>(getvdim);
    double* dblarray = valloc<double>(getvdim);

    cout << "Insert the elements of the array..." << endl;

    for (size_t getelem = 0; getelem < getvdim; getelem++)
    {
        cin >> dblarray[getelem];
        intarray[getelem] = static_cast<int>(dblarray[getelem]);
    }

    printrev(dblarray, getvdim);
    printrev(intarray, getvdim);

    delete[] intarray;
    delete[] dblarray;

    return 0;
}
