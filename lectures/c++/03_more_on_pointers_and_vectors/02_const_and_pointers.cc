#include <iostream>

template<typename T>
void print_sentinel(const T* a, const std::size_t l);

int main()
{
    int a{8}, b{7};
    int* pi{&a};

    // The dereferenced pointer is CONSTANT. The variable value is FIXED.
    const int* pc{&a};
    // *pc = 7; 	// error
    a = 15;  // I can obviously change a

    // The pointer address is constant, not the pointer variable.
    int* const cp{&a};
    a = b;
    *cp = 33;
    // cp = &b;   // error

    const int* const cpc{&a};

    // *cpc = 0;  // error
    // cpc = &n;  // error
    a = 99;

    int aa[4]{};
    print_sentinel(aa, 4);

    return 0;
}

template<typename T>
void print_sentinel(const T* a, const std::size_t N)
{
    const T* const end{
      a + N};  // Pointer to the LAST element, plus one. a[N] must remain constant, because it is not part of a.
    for (; a != end; ++a) std::cout << *a << std::endl;  // Methodology of "pointer arithmetics" as in the STL.
}
