#include "libraries/linked_list/LinkedList.h"
#include "Stack.h"


template<typename T>
Stack<T>::Stack () {}

template<typename T>
Stack<T>::~Stack () {
    mList.destroy();
}

template<typename T>
T& Stack<T>::getTopItem () {
    LinkedNode<T>* ptrToLastNode = mList.getLast();

    if (ptrToLastNode == (LinkedNode<T>*)0) {
        throw "Stack is empty, can't get top item node's value";
    }

    return ptrToLastNode->mValue;
}

template<typename T>
bool Stack<T>::isEmpty (void) {
    return mList.isEmpty();
}

template<typename T>
void Stack<T>::push (T newElement) {
    mList.insertLast(newElement);
}

template<typename T>
void Stack<T>::pop () {
    mList.removeLast();
}
