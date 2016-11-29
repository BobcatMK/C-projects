#include <iostream>
#include "array.h"

using namespace std;

#define ONE_SPACE cout << "\n";
#define TWO_SPACES cout << "\n\n";
#define L << " " <<

template <typename T>
void PrintArray(Array<T>& fa) {
    // insertion operator needs to be overloaded for custom variable types to work
    cout << "{ ";
    for(int i = 0; i < fa.size(); ++i)
    cout << fa[i] << " ";
    cout << "}" << endl << endl;
}

int main() {
    Array<string> A;
    A.resize(4);
    A[0] = "a";
    A[1] = "b";
    A[2] = "c";
    A[3] = "d";
    cout << "Printing A: ";
    PrintArray(A);
    Array<string> B(A);
    cout << "Printing B: ";
    PrintArray(B);
    Array<string> C = B = A;
    cout << "Printing C: ";
    PrintArray(C);
    A = A = A = A;
    cout << "Printing A: ";
    PrintArray(A);
}
