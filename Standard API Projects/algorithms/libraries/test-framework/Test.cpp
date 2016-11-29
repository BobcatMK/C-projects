#include <iostream>
#include <string>
#include "Test.h"

using namespace std;
using namespace Test;

#define ONE_SPACE cout << "\n";
#define TWO_SPACES cout << "\n\n";
#define L << " " <<

template <typename T>
void Test::debug(T debugVariable, string description) {
    // remember about overloading insertion operator for your personal types of data
    ONE_SPACE
    cout << "DEBUG " + description + " >>>>> " << debugVariable;
    ONE_SPACE
}

void Test::separator(string description) {
    ONE_SPACE
    cout << "<<<<<<<<<<<<<<<<<<<< " << description << " >>>>>>>>>>>>>>>>>>>>";
    ONE_SPACE    
}

template <typename T>
void Test::eq(string testDescription, T testVariable, T valueToMatch) {
    ONE_SPACE
    if (testVariable != valueToMatch) {
        cout << "    Test FAILED: " << testDescription;
        return;
    }

    cout << "    Test SUCCESS: " << testDescription;
}
    
template <typename T>
void Test::notEq(string testDescription, T testVariable, T valueToMatch) {
    ONE_SPACE
    if (testVariable == valueToMatch) {
        cout << "    Test FAILED: " << testDescription;
        return;
    }

    cout << "    Test SUCCESS: " << testDescription;
}

void Test::suite(string suiteDescription) {
    ONE_SPACE
    cout << "<< Test suite: " << suiteDescription << " >>";
}

void Test::suiteEnd() {
    ONE_SPACE
    cout << "<< Test suite END >>";
}
