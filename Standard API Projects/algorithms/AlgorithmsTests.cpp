#include "libraries/test-framework/Test.cpp"
#include "Algorithms.cpp"
#include "libraries/helpers/helpers.cpp"


template<typename T>
struct LogElement {
    // remember about overloading insertion operator for your own datatypes 
    void operator() (T item);
};

template<typename T>
void LogElement<T>::operator() (T item) {
    ONE_SPACE
    std::cout << "Item value = " << item;
    ONE_SPACE
}

int main () {
    // half automatic half manual test for LogElement functor struct - if you can see "Item value = LOGGING" then test passes
    LogElement<std::string> logElement;
    logElement("LOGGING");

    // automatic tests for Algorithms.cpp
    // half automatic half manual test for for_each algorithms - it's only cout each item in array
    LogElement<int> logElementInt;
    int firstArray[10] = {14,13,76,342,32,12,54,54,1,5};
    for_each(firstArray, 10, logElementInt);

    Test::suite("test count algorithm with array {14,13,76,342,32,12,54,54,1,5}");
        Test::eq("count() algorithm returns 2 for integer 54", count(firstArray, 10, 54), 2);
        Test::eq("count() algorithm returns 1 for integer 342", count(firstArray, 10, 342), 1);
        Test::eq("count() algorithm returns 0 for integer 999", count(firstArray, 10, 999), 0);
    Test::suiteEnd();

    Test::suite("test reverse algorithm with array {14,13,76,342,32,12,54,54,1,5}");
        reverse(firstArray, 10);
        int manuallyReversedArray[10] = {5,1,54,54,12,32,342,76,13,14};
        for (int i = 0; i < 10; i++) {
            Test::eq("reverse() algorithm returns " + std::to_string(manuallyReversedArray[i]) + " for " + std::to_string(i) + " element", firstArray[i], manuallyReversedArray[i]);    
        }
    Test::suiteEnd();

    Test::suite("test sort algorithm with array {5,1,54,54,12,32,342,76,13,14}");
        sort(firstArray, 10);
        int manuallySortedArray[10] = {1,5,12,13,14,32,54,54,76,342};
        for (int i = 0; i < 10; i++) {
            Test::eq("sort() algorithm returns " + std::to_string(manuallySortedArray[i]) + " for " + std::to_string(i) + " element", firstArray[i], manuallySortedArray[i]);    
        }
    Test::suiteEnd();
    return 0;
}
