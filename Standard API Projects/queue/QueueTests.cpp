#include "libraries/linked-list/LinkedList.cpp"
#include "libraries/test-framework/Test.cpp"
#include "Queue.cpp"

int main () {
    Test::suite("Creating queue and checking if it's empty");
        Queue<int> firstQueue;
        Test::eq("Queue is empty", firstQueue.isEmpty(), true);
    Test::suiteEnd();

    Test::suite("Push two items into queue 50, 100, now it looks like this = {50, 100}");
        firstQueue.push(50);
        firstQueue.push(100);
        Test::eq("First item is eq to 50", firstQueue.getFirst(), 50);
    Test::suiteEnd();

    Test::suite("Removing first element with .pop()");
        firstQueue.pop();
        Test::eq("Last item left should be equal to 100", firstQueue.getFirst(), 100);
    Test::suiteEnd();

    Test::suite("Removing last element with .pop()");
        firstQueue.pop();
        Test::eq("queue is empty", firstQueue.isEmpty(), true);
        try {
            firstQueue.getFirst();
        } catch (char const* e) {
            Test::eq("getting first value when queue is empty throws error - 'Queue is empty, can't get first node's value'", e, "Queue is empty, can't get first node's value");
        }
    Test::suiteEnd();
    return 0;
}
