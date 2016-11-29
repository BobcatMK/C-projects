#ifndef EMPLOYEE_H
    #define EMPLOYEE_H
    #include "Employee.h"
    
    class Employee {
        public: 
            virtual ~Employee() {};

            Employee(std::string employeeType, std::string firstName, std::string lastName, int salary) {
                mEmployeeType = employeeType;
                mFirstName = firstName;
                mLastName = lastName;
                mSalary = salary;
            };

            virtual void getInfo() = 0; // pure virtual

            virtual std::string getEmployeeType() = 0; // pure virtual
            virtual std::string getFirstName() = 0; // pure virtual
            virtual std::string getLastName() = 0; // pure virtual
            virtual int getSalary() = 0; // pure virtual
            
            // Engineer methods
            virtual bool getKnowsCpp() { return true; };
            virtual int getYearsOfExperience() { return 0; };
            virtual std::string getEngineerType() { return "default"; };
            
            // Researcher methods
            virtual std::string getPhdMadeAt() { return "default"; };
            virtual std::string getPhdTopic() { return "default"; };

            // Manager methods
            virtual int getMeetingsPerWeek() { return 0; };
            virtual int getHolidaysPerYear() { return 0; };

        protected:
            std::string mEmployeeType;
            std::string mFirstName;
            std::string mLastName;
            int mSalary;
    };
#endif
