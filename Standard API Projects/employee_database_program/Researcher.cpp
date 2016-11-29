#include <iostream>
#include "Employee.h"
#include "Researcher.h"

using namespace std;

Researcher::Researcher(
    std::string employeeType, 
    std::string firstName,
    std::string lastName,
    int salary,
    std::string phdMadeAt,
    std::string phdTopic
)
: Employee(employeeType, firstName, lastName, salary) {
    mPhdMadeAt = phdMadeAt;
    mPhdTopic = phdTopic;
}

Researcher::~Researcher() {
}

void Researcher::getInfo() {
    cout << "====================";
    cout << "\n";
    cout << "employeeType = " << mEmployeeType << "\n";
    cout << "firstName = " << mFirstName << "\n";
    cout << "lastName = " << mLastName << "\n";
    cout << "salary = " << mSalary << "\n";
    cout << "phdMadeAt = " << mPhdMadeAt << "\n";
    cout << "phdTopic = " << mPhdTopic << "\n";
    cout << "====================";
}

string Researcher::getEmployeeType() {
    return mEmployeeType;
}

string Researcher::getFirstName() {
    return mFirstName;
}

string Researcher::getLastName() {
    return mLastName;
}

int Researcher::getSalary() {
    return mSalary;
}

string Researcher::getPhdMadeAt() {
    return mPhdMadeAt;
}

string Researcher::getPhdTopic() {
    return mPhdTopic;
}