#ifndef RESEARCHER_H
    #define RESEARCHER_H
    #include "Employee.h"
    
    class Researcher : public Employee {
        public: 
            virtual ~Researcher();

            void getInfo();
            
            std::string getEmployeeType();
            std::string getFirstName();
            std::string getLastName();
            int getSalary();
            std::string getPhdMadeAt();
            std::string getPhdTopic();

            Researcher(
                std::string employeeType, 
                std::string firstName,
                std::string lastName,
                int salary,
                std::string phdMadeAt,
                std::string phdTopic
            );
        protected:
            std::string mPhdMadeAt;
            std::string mPhdTopic;
    };
#endif
