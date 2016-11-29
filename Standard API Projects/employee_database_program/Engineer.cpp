#include <iostream>
#include "Engineer.h"
#include "Employee.h"

using namespace std;

Engineer::Engineer(
    std::string employeeType, 
    std::string firstName, 
    std::string lastName, 
    int salary, 
    bool knowsCpp, 
    int yearsOfExp, 
    std::string engineerType
) : Employee(employeeType, firstName, lastName, salary) {
    mKnowsCpp = knowsCpp;
    mYearsOfExp = yearsOfExp;
    mEngineerType = engineerType;
}

Engineer::~Engineer() {
}

void Engineer::getInfo() {
    cout << "====================";
    cout << "\n";
    cout << "employeeType = " << mEmployeeType << "\n";
    cout << "firstName = " << mFirstName << "\n";
    cout << "lastName = " << mLastName << "\n";
    cout << "salary = " << mSalary << "\n";
    cout << "knowsCpp = " << mKnowsCpp << "\n";
    cout << "yearsOfExp = " << mYearsOfExp << "\n";
    cout << "engineerType = " << mEngineerType << "\n";
    cout << "====================";
}

string Engineer::getEmployeeType() {
    return mEmployeeType;
}

string Engineer::getFirstName() {
    return mFirstName;
}

string Engineer::getLastName() {
    return mLastName;
}

int Engineer::getSalary() {
    return mSalary;
}

bool Engineer::getKnowsCpp() {
    return mKnowsCpp;
}

int Engineer::getYearsOfExperience() {
    return mYearsOfExp;
}

string Engineer::getEngineerType() {
    return mEngineerType;
}
