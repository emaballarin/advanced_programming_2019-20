// INCLUDES
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>


// DEFINES
#define usl unsigned long int


// NS DECLARATIONS
using namespace std;


// PROTOTYPES
template <size_t arraydim>
array<double, arraydim> transpose(array<double, arraydim> matrix, size_t rows);

template <size_t arraydim>
void printmatrix_byrow(array<double, arraydim> matrix, size_t rows);


// FUNC IMPLEMENTATIONS
template <size_t arraydim>
array<double, arraydim> transpose(array<double, arraydim> matrix, size_t rows)
{
    array<double, arraydim> retmatrix{};
    size_t cols{static_cast<size_t>(arraydim / rows)};

    // Notes:
    // - inverted rows/cols limits (i.e. we start from the resulting matrix);
    // - "solve" the print algorithm for (i,j) = (j,i) starting from the result
    for (usl i{0}; i < cols; ++i)
    {
        for (usl j{0}; j < rows; ++j) { retmatrix[i * rows + j] = matrix[j * cols + i]; }
    }
    return retmatrix;
}

template <size_t arraydim>
void printmatrix_byrow(array<double, arraydim> matrix, size_t rows)
{
    size_t cols{static_cast<size_t>(arraydim / rows)};

    for (usl i{0}; i < rows; ++i)
    {
        for (usl j{0}; j < cols; ++j) { cout << setw(6) << matrix[i * cols + j] << " "; }
        cout << endl;
        cout << endl;
    }
}


// MAIN
int main(int argc, char *argv[])
{
    // This script must be called as:
    // 01_02_transpose.x [rows]
    // where [rows] is the number of rows of the matrix that it is needed to be
    // transposed.
    // The program then should ask the user for the elements of such matrix -
    // which are of fixed number -, transpose it, and print as the final result
    // the given matrix and the transposed matrix.

    // Suppress warning
    static_cast<void>(argc);

    size_t const nrelem = 10;

    // Get [rows]
    size_t rows;
    usl getrows;
    {
        istringstream is{argv[1]};
        is >> getrows;
        rows = static_cast<size_t>(getrows);
    }

    size_t cols{nrelem / rows};

    array<double, nrelem> initial_matrix;  // To be filled by the user!

    // Fill the matrix
    cout << endl;
    cout << endl;
    cout << "Please, fill a matrix of " << nrelem << " "
         << "elements (" << rows << " rows)..." << endl;
    cout << endl;
    for (size_t getelem{0}; getelem < nrelem; getelem++)
    {
        double double_element_get{};
        cin >> double_element_get;
        initial_matrix[getelem] = static_cast<double>(double_element_get);
    }


    // Transpose!
    array<double, nrelem> final_matrix{transpose<nrelem>(initial_matrix, rows)};

    // PRINTOUT:
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "GIVEN MATRIX:" << endl;
    cout << endl;
    cout << endl;
    printmatrix_byrow<nrelem>(initial_matrix, rows);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "TRANSPOSED MATRIX:" << endl;
    cout << endl;
    cout << endl;

    // Pass "cols" (of original matrix) as [rows] of the transposed matrix.
    printmatrix_byrow<nrelem>(final_matrix, cols);
}
