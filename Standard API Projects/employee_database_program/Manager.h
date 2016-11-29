#ifndef MANAGER_H
    #define MANAGER_H
    
    class Manager : public Employee {
        public: 
            virtual ~Manager();

            void getInfo();

            std::string getEmployeeType();
            std::string getFirstName();
            std::string getLastName();
            int getSalary();
            int getMeetingsPerWeek();
            int getHolidaysPerYear();

            Manager(
                std::string employeeType,
                std::string firstName, 
                std::string lastName, 
                int salary, 
                int meetingsPerWeek, 
                int holidaysPerYear
            );
        protected:
            int mMeetingsPerWeek;
            int mHolidaysPerYear;
    };
#endif