#include <iostream>
#include "Employee.h"
#include "Manager.h"

using namespace std;

Manager::Manager(
    std::string employeeType,
    std::string firstName, 
    std::string lastName, 
    int salary, 
    int meetingsPerWeek, 
    int holidaysPerYear
)
: Employee(employeeType, firstName, lastName, salary) {
    mMeetingsPerWeek = meetingsPerWeek;
    mHolidaysPerYear = holidaysPerYear;
}

Manager::~Manager() {
}

void Manager::getInfo() {
    cout << "====================";
    cout << "\n";
    cout << "employeeType = " << mEmployeeType << "\n";
    cout << "firstName = " << mFirstName << "\n";
    cout << "lastName = " << mLastName << "\n";
    cout << "salary = " << mSalary << "\n";
    cout << "meetingsPerWeek = " << mMeetingsPerWeek << "\n";
    cout << "holidaysPerYear = " << mHolidaysPerYear << "\n";
    cout << "====================";
}

string Manager::getEmployeeType() {
    return mEmployeeType;
}

string Manager::getFirstName() {
    return mFirstName;
}

string Manager::getLastName() {
    return mLastName;
}

int Manager::getSalary() {
    return mSalary;
}

int Manager::getMeetingsPerWeek() {
    return mMeetingsPerWeek;
}

int Manager::getHolidaysPerYear() {
    return mHolidaysPerYear;
}
