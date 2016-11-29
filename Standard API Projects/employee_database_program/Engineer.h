#ifndef ENGINEER_H
    #define ENGINEER_H
    #include "Employee.h"
    
    class Engineer : public Employee {
        public: 
            virtual ~Engineer();

            void getInfo();

            std::string getEmployeeType();
            std::string getFirstName();
            std::string getLastName();
            int getSalary();
            bool getKnowsCpp();
            int getYearsOfExperience();
            std::string getEngineerType();
            
            Engineer(
                std::string employeeType, 
                std::string firstName, 
                std::string lastName, 
                int salary, 
                bool knowsCpp, 
                int yearsOfExp, 
                std::string engineerType
            );
        protected:
            bool mKnowsCpp;
            int mYearsOfExp;
            std::string mEngineerType;
    };
#endif
