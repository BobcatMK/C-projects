#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
#include <string>
#include "Engineer.h"
#include "Employee.h"
#include "Researcher.h"
#include "Manager.h"


using namespace std;

#define ONE_SPACE cout << "\n";
#define TWO_SPACES cout << "\n\n";
#define L << " " <<

template <typename T>
void debugger(T debugVariable, string description) {
    ONE_SPACE
    cout << "DEBUGGER " + description + " >>>>> " << debugVariable;
    ONE_SPACE
}

void debugger(char debugVariable, string description) {
    ONE_SPACE
    cout << "DEBUGGER " + description + " >>>>> " << debugVariable;
    ONE_SPACE
}

void debugger(int debugVariable, string description) {
    ONE_SPACE
    cout << "DEBUGGER " + description + " >>>>> " << debugVariable;
    ONE_SPACE
}


void addDataToEmployeeData(vector<string>& employeeData, string messageString) {
    string dataHolder = "";
    ONE_SPACE
    cout << messageString;
    getline(cin, dataHolder);
    employeeData.push_back(dataHolder);
}

void addBasicInfo(vector<string>& employeeData, string employeeType) {
    int employeeTypeSize = employeeType.size();

    employeeData.push_back(employeeType); // we push employee type automatically, no user action is required for this

    char* employeeTypeLc = new char[employeeTypeSize + 1];
    employeeTypeLc[employeeTypeSize] = '\0';

    for (int i = 0; i < employeeTypeSize; i++) {
        employeeTypeLc[i] = std::tolower(employeeType[i]);
    }

    cin.ignore(5, '\n'); // necessary for getline to ignore newline characater leftover in buffer made by insertion operator
    addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s first name: ");
    addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s last name: ");
    addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s salary: ");

    if (employeeType == "Manager") {
        addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s meetings per week: ");
        addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s holidays per year: ");
    }

    if (employeeType == "Engineer") {
        addDataToEmployeeData(employeeData, "Please enter if " + (string)employeeTypeLc + " knows cpp: ");
        addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s years of experience: ");
        addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s type of engineering: ");
    }

    if (employeeType == "Researcher") {
        addDataToEmployeeData(employeeData, "Please enter where " + (string)employeeTypeLc + " made his PHD: ");
        addDataToEmployeeData(employeeData, "Please enter " + (string)employeeTypeLc + "'s PHD's topic: ");
    }

    delete[] employeeTypeLc;
};

void addManager(vector<string>& employeeData) {
    addBasicInfo(employeeData, "Manager");
};

void addEngineer(vector<string>& employeeData) {
    addBasicInfo(employeeData, "Engineer");
};

void addResearcher(vector<string>& employeeData) {
    addBasicInfo(employeeData, "Researcher");
};

void saveEmployee(vector<Employee*>& dbEmployees, vector<string>& employeeData) {
    if (employeeData[0] == "Engineer") {

        cout << "XXXXXXXXXXXX -> " << employeeData[4] << " <- XXXXXXXXXX";
        dbEmployees.push_back(new Engineer(
            employeeData[0],
            employeeData[1],
            employeeData[2],
            stoi(employeeData[3]),
            employeeData[4] == "true" ? true : false,
            stoi(employeeData[5]),
            employeeData[6]
        ));
    } else if (employeeData[0] == "Manager") {
        dbEmployees.push_back(new Manager(
            employeeData[0],
            employeeData[1],
            employeeData[2],
            stoi(employeeData[3]),
            stoi(employeeData[4]),
            stoi(employeeData[5])
        ));
    } else if (employeeData[0] == "Researcher") {
        dbEmployees.push_back(new Researcher(
            employeeData[0],
            employeeData[1],
            employeeData[2],
            stoi(employeeData[3]),
            employeeData[4],
            employeeData[5]
        ));
    }
}

void showEmployees(vector<Employee*>& dbEmployees) {
    for (int i = 0; i < dbEmployees.size(); i++) {
        ONE_SPACE
        dbEmployees[i]->getInfo();
        ONE_SPACE
    }
}

void addEmployee(vector<Employee*>& dbEmployees, vector<string>& employeeData) {
    int userChoice = 1;
    employeeData.clear();

    ONE_SPACE
    cout << "Select the employee you want to add: 1) Manager, 2) Engineer, 3) Researcher: ";
    cin >> userChoice;

    switch(userChoice) {
        case 1:
            addManager(employeeData);
            break;
        case 2:
            addEngineer(employeeData);
            break;
        case 3:
            addResearcher(employeeData);
            break;
        default:
            break;
    }
}

void deleteEmployee(vector<Employee*>& dbEmployees) {
    string employeeLastName = ""; 
    cin.ignore(5, '\n');
    ONE_SPACE
    cout << "Type in employee's last name which you want to delete: ";
    getline(cin, employeeLastName);
    ONE_SPACE

    for (int i = 0; i < dbEmployees.size(); i++) {
        if (dbEmployees[i]->getLastName() == employeeLastName) {
            delete dbEmployees[i];
            dbEmployees[i] = 0;
            dbEmployees.erase(dbEmployees.begin() + i);
        }
    }
}

void saveDatabase(vector<Employee*>& dbEmployees) {
    ofstream outFile("database.txt");

    for (int i = 0; i < dbEmployees.size(); i++) {
        outFile << "employeeType = " << dbEmployees[i]->getEmployeeType() << '\n';
        outFile << "firstName = " << dbEmployees[i]->getFirstName() << '\n';
        outFile << "lastName = " << dbEmployees[i]->getLastName() << '\n';
        outFile << "salary = " << dbEmployees[i]->getSalary() << '\n';

        if (dbEmployees[i]->getEmployeeType() == "Manager") {
            outFile << "meetingsPerWeek = " << dbEmployees[i]->getMeetingsPerWeek() << '\n';
            outFile << "holidaysPerYear = " << dbEmployees[i]->getHolidaysPerYear() << '\n';
        } else if (dbEmployees[i]->getEmployeeType() == "Engineer") {
            outFile << "knowsCpp = " << dbEmployees[i]->getKnowsCpp() << '\n';
            outFile << "yearsOfExp = " << dbEmployees[i]->getYearsOfExperience() << '\n';
            outFile << "engineerType = " << dbEmployees[i]->getEngineerType() << '\n';
        } else {
            outFile << "phdMadeAt = " << dbEmployees[i]->getPhdMadeAt() << '\n';
            outFile << "phdTopic = " << dbEmployees[i]->getPhdTopic() << '\n';
        }

        outFile << endl; // finish inserting particular employee with new line
    }

    outFile.close();
}

int main() {
    cout.setf(ios::boolalpha); // this is required for program to insert booleans to ofstream

    bool exitProgram = false;
    string lineOfText = "";
    ifstream inFile("database.txt");
    vector<Employee*> dbEmployees;
    vector<string> employeeData;
    int userChoice = 1;
    regex regexToMatch("(.+)\\s=\\s(.+)", regex_constants::ECMAScript | regex_constants::icase);
    smatch matchObj;
    bool found = false;

    while (!inFile.eof()) {
        getline(inFile, lineOfText);
        found = regex_search(lineOfText, matchObj, regexToMatch);

        if (found && matchObj.size() == 3) {
            if (matchObj[1].str() == "employeeType") {
                employeeData.clear(); // if employeeType is read from the file then it means we encountered new employee - clear employeeData container
            }
            employeeData.push_back(matchObj[2].str());

            if ((employeeData[0] == "Manager" || employeeData[0] == "Researcher") && employeeData.size() == 6) {
                saveEmployee(dbEmployees, employeeData);
                employeeData.clear();
            } else if (employeeData[0] == "Engineer" && employeeData.size() == 7) {
                saveEmployee(dbEmployees, employeeData);
                employeeData.clear();
            }
        } else {
            employeeData.clear(); // clearing employeeData - why? because if this block of code is exectured then it means that employee data might not be complete
        }
    }

    cout << "Welcome to employees database v1.0";
    ONE_SPACE

    cout << "Please select one option:";
    ONE_SPACE

    while (!exitProgram) {
        cout << "1) Show Employees, 2) Add an Employee, 3) Delete an Employee, 4) Save Database, 5) Exit: ";
        cin >> userChoice;
        ONE_SPACE

        switch(userChoice) {
            case 1:
                showEmployees(dbEmployees);
                break;
            case 2:
                addEmployee(dbEmployees, employeeData);
                saveEmployee(dbEmployees, employeeData);
                break;
            case 3:
                deleteEmployee(dbEmployees);
                break;
            case 4:
                inFile.close();
                saveDatabase(dbEmployees);
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                break;
        }
    }
    // delete all employees from RAM
    for (int i = 0; i < dbEmployees.size(); i++) {
        delete dbEmployees[i];
        dbEmployees[i] = 0;
    }

    if (inFile.is_open()) {
        inFile.close();    
    }
    
    return 0;
}
