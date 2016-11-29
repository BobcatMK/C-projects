#include <iostream>
#include "libraries/test-framework/Test.cpp"
#include "LinkedList.cpp"
#include "LinkedNode.h"

using namespace std;


int main () {
    std::cout.setf(std::ios::boolalpha);

    LinkedList<int> firstList;
    Test::suite("checking if list is empty");
        Test::eq("firstList is empty", firstList.isEmpty(), true);
    Test::suiteEnd();

    Test::suite("inserting two elements integer 5 and 10");
        firstList.insertLast(5);
        firstList.insertLast(10);
        Test::eq("elements inserted - firstList is NOT empty", firstList.isEmpty(), false);
        Test::eq("first node value is 5", firstList.getFirst()->mValue, 5);
        Test::eq("first node mPreviousNode pointer is 0", firstList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::notEq("first node mNextNode pointer is NOT 0", firstList.getFirst()->mNextNode, (LinkedNode<int>*)0);
        Test::eq("last node value is 10", firstList.getLast()->mValue, 10);
        Test::notEq("last node mPreviousNode pointer is NOT 0", firstList.getLast()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("last node mNextNode pointer is 0", firstList.getLast()->mNextNode, (LinkedNode<int>*)0);
    Test::suiteEnd();

    Test::suite("removing second (last) node");
        firstList.remove(10);
        Test::eq("first and last LinkedList's elements are the same", firstList.getFirst(), firstList.getLast());
        Test::eq("the LinkedList's only element mNextNode ptr is NULL", firstList.getFirst()->mNextNode, (LinkedNode<int>*)0);
        Test::eq("the LinkedList's only element mPreviousNode ptr is NULL", firstList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
    Test::suiteEnd();

    Test::suite("removing the only node present in LinkedList");
        firstList.remove(5);
        Test::eq("first and last LinkedList's elements are the same", firstList.getFirst(), firstList.getLast());
        Test::eq("first and last LinkedList's elements are the same and are equal to zero", firstList.getFirst(), (LinkedNode<int>*)0);
    Test::suiteEnd();

    Test::suite("inserting new four elements - with insertLast");
        firstList.insertLast(25);
        firstList.insertLast(50);
        firstList.insertLast(75);
        firstList.insertLast(100);
        Test::eq("first LinkedList's element value is 25", firstList.getFirst()->mValue, 25);
        Test::eq("last LinkedList's element value is 100", firstList.getLast()->mValue, 100);
    Test::suiteEnd();

    Test::suite("destroying all LinkedList's nodes");
        firstList.destroy();
        Test::eq("LinkedList is empty", firstList.isEmpty(), true);
    Test::suiteEnd();

    Test::suite("inserting new four elements - with insertLast");
        firstList.insertFirst(25);
        firstList.insertFirst(50);
        firstList.insertFirst(75);
        firstList.insertFirst(100);
        Test::notEq("LinkedList is NOT empty", firstList.isEmpty(), true);
        Test::eq("first LinkedList's element value is 100", firstList.getFirst()->mValue, 100);
        Test::eq("last LinkedList's element value is 25", firstList.getLast()->mValue, 25);
    Test::suiteEnd();

    Test::suite("inserting 125 value node after last node");
        firstList.insertAfter(25, 125);
        Test::notEq("LinkedList is NOT empty", firstList.isEmpty(), true);
        Test::eq("last LinkedList's element value is 125", firstList.getLast()->mValue, 125);
        Test::eq("last LinkedList's element mNextNode is NULL pointer", firstList.getLast()->mNextNode, (LinkedNode<int>*)0);
        Test::notEq("last LinkedList's element mPreviousNode is NOT NULL pointer", firstList.getLast()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("one before last LinkedList's element value is 25", firstList.getLast()->mPreviousNode->mValue, 25);
        Test::eq("one before last LinkedList's element mNextNode is pointing to node with value 125", firstList.getLast()->mPreviousNode->mNextNode->mValue, 125);
        Test::eq("one before last LinkedList's element mPreviousNode is pointing to node with value 50", firstList.getLast()->mPreviousNode->mPreviousNode->mValue, 50);
    Test::suiteEnd();

    Test::suite("testing removeFirst LinkedList's method - LinkedList looks like this so far {100, 75, 50, 25, 125}");
        firstList.removeFirst();
        Test::eq("LinkedList first node value is 75", firstList.getFirst()->mValue, 75);
        Test::eq("LinkedList first node mPreviousNode ptr is NULL", firstList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("LinkedList first node mNextNode is pointing to node with value of 50", firstList.getFirst()->mNextNode->mValue, 50);
    Test::suiteEnd();

    Test::suite("testing removeLast LinkedList's method - LinkedList looks like this so far {75, 50, 25, 125}");
        firstList.removeLast();
        Test::eq("LinkedList last node value is 25", firstList.getLast()->mValue, 25);
        Test::eq("LinkedList last node mNextNode ptr is NULL", firstList.getLast()->mNextNode, (LinkedNode<int>*)0);
        Test::eq("LinkedList last node mPreviousNode is pointing to node with value of 50", firstList.getLast()->mPreviousNode->mValue, 50);
    Test::suiteEnd();    

    Test::suite("test getFirst() and getLast() methods - LinkedList so far = {75, 50, 25}");
        Test::eq("LinkedList first node value is 75", firstList.getFirst()->mValue, 75);
        Test::eq("LinkedList last node value is 25", firstList.getLast()->mValue, 25);
    Test::suiteEnd();

    Test::suite("secondList was created and it looks like this {30, 60, 90} I want firstList to look the same - using '=' operator");
        LinkedList<int> secondList;
        secondList.insertLast(30);
        secondList.insertLast(60);
        secondList.insertLast(90);
        firstList = secondList;

        Test::eq("firstList first node mPreviousNode is NULL ptr", firstList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("firstList first node value is 30", firstList.getFirst()->mValue, 30);
        Test::eq("firstList second node value is 60", firstList.getFirst()->mNextNode->mValue, 60);
        Test::eq("firstList last node value is 90", firstList.getFirst()->mNextNode->mNextNode->mValue, 90);
        Test::eq("firstList last node mNextNode is NULL ptr", firstList.getLast()->mNextNode, (LinkedNode<int>*)0);
    Test::suiteEnd();

    Test::suite("thirdList was created and I want it to look the same as firstList which is {30, 60, 90} I use contructor with LinkedList<int>& as an argument");
        LinkedList<int> thirdList(firstList);
        Test::eq("thirdList first node mPreviousNode is NULL ptr", thirdList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("thirdList first node value is 30", thirdList.getFirst()->mValue, 30);
        Test::eq("thirdList second node value is 60", thirdList.getFirst()->mNextNode->mValue, 60);
        Test::eq("thirdList last node value is 90", thirdList.getFirst()->mNextNode->mNextNode->mValue, 90);
        Test::eq("thirdList last node mNextNode is NULL ptr", thirdList.getLast()->mNextNode, (LinkedNode<int>*)0);
    Test::suiteEnd();

    Test::suite("third list is emptied with .destroy(), then we insertFirst two elements 25, 50 - {50, 25} and removeFirst() until it's empty");
        thirdList.destroy();

        Test::eq("third list is empty after destroy", thirdList.isEmpty(), true);

        thirdList.insertFirst(25);
        thirdList.insertFirst(50);

        Test::eq("third list first node mPreviousNode is NULL ptr", thirdList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("third list first node value is 50", thirdList.getFirst()->mValue, 50);
        Test::eq("third list first node mNextNode ptr is pointing to node with value 25", thirdList.getFirst()->mNextNode, thirdList.getLast());

        Test::eq("third list last node mPreviousNode ptr is pointing to node with value 50", thirdList.getLast()->mPreviousNode, thirdList.getFirst());
        Test::eq("third list last node value is 25", thirdList.getLast()->mValue, 25);
        Test::eq("third list last node mNextNode is NULL ptr", thirdList.getLast()->mNextNode, (LinkedNode<int>*)0);

        thirdList.removeFirst();
        Test::eq("thirdList first and last node is the same", thirdList.getFirst(), thirdList.getLast());
        Test::notEq("thirdList first and last node is not NULL ptr", thirdList.getFirst(), (LinkedNode<int>*)0);
        Test::eq("thirdList only node value is 25", thirdList.getFirst()->mValue, 25);
        Test::eq("third list only node mPreviousNode is NULL ptr", thirdList.getFirst()->mPreviousNode, (LinkedNode<int>*)0);
        Test::eq("third list only node mNextNode is NULL ptr", thirdList.getFirst()->mNextNode, (LinkedNode<int>*)0);

        thirdList.removeFirst();
        Test::eq("third list after removal of last element is empty", thirdList.isEmpty(), true);
    Test::suiteEnd();

    return 0;
};
