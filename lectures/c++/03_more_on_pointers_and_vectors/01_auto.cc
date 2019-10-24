#include <cmath>
#include <iostream>

// 201103L is the official string of version "C++ 2011". If more than that, it's at least C++14.
#if __cplusplus > 201103L

// Templated heap inizialization (for the new keyword; and auto return type (C++14))
template<class T>
auto init(const std::size_t l)
{
    return new T[l]{};
}

#else

// Templated heap inizialization (for the new keyword; WITHOUT auto return type (C++11))
template<class T>
T* init(const std::size_t l)
{
    return new T[l]{};
}

#endif

int main()
{
    auto b = true;          // a bool
    auto ch = 'x';          // a char
    auto i = 123;           // an int
    auto d = 1.2;           // a double
    auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
    auto ui = 0u;           // unsigned int
    auto llui = 0llu;       // long long unsigned int

    for (auto i = 0; i < 7; ++i) std::cout << i << std::endl;

    auto pb = &b;  // guess what.. How can I know?

    auto ps = init<double>(11);
    delete[] ps;
    return 0;
}
