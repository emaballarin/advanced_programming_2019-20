#include <iostream>     // cout, endl

int main()
{
    std::cout << "Hello, World!" << std::endl;
}

/*
 * From the prototype "Hello World" program above:
 *
 * a) Missing main()            -> Linking error, undefined reference to `main'.
 * b) Typos in library name     -> ‘errored_name’ is not a member of ‘std’; suggestion is provided if the name is similar.
 * c) Typos in variable name    -> use of undeclared identifier 'errored_name'; suggestion is provided.
 * d) Missing semicolon         -> expected ';' after expression.
 * e) Missing include           -> error: ‘something’ is not a member of ‘namespace_used’; eventually suggestion is provided (g++ 9.x)
 * f) Illegal variable name     -> generic type error; place is specified anyway.
 *
 * Of these errors, all (except "a" which can be acceptable in some source files) can be prevented by using a realtime static analyzer/linter such as clangd.
 */
