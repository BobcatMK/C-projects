#include <iostream>
#include "libraries/test-framework/Test.cpp"
#include "libraries/linked_list/LinkedList.cpp"
#include "Stack.cpp"

using namespace std;


int main () {
    Test::suite("Creating stack and checking if it's empty - testing constructor and isEmpty()");
        Stack<int> firstStack;
        Test::eq("Stack is empty", firstStack.isEmpty(), true);
    Test::suiteEnd();

    Test::suite("Pushing two items onto stack - stack looks like this = {25, 50}");
        firstStack.push(50);
        firstStack.push(25);
        Test::eq("first item on stack with getTopItem() is eq to 25", firstStack.getTopItem(), 25);
        firstStack.pop();
        Test::eq("poping item to get to second value - which is equal to 50", firstStack.getTopItem(), 50);
        firstStack.pop();
        Test::eq("popped last item - stack is now empty", firstStack.isEmpty(), true);
    Test::suiteEnd();

    Test::suite("Getting top item when stack is empty");
        try {
            firstStack.getTopItem();
        } catch (char const* e) {
            Test::eq("getting top item's value when queue is empty throws error - 'Stack is empty, can't get top item node's value'", e, "Stack is empty, can't get top item node's value");
        }
    Test::suiteEnd();

    return 0;
}
