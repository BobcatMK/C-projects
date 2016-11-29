#ifndef TEST_H
    #define TEST_H
    #include <string>

    namespace Test {
        template <typename T> void debug(T debugVariable, std::string description);
        void separator(std::string description);
        template <typename T> void eq(std::string testDescription, T testVariable, T valueToMatch);
        template <typename T> void notEq(std::string testDescription, T testVariable, T valueToMatch);
        void suite(std::string suiteDescription);
        void suiteEnd();
    }
#endif
