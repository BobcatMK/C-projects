#include "Queue.h"
#include "libraries/linked-list/LinkedList.h"
#include "libraries/linked-list/LinkedNode.h"


template<class T>
Queue<T>::Queue () {};

template<class T>
Queue<T>::~Queue () {
    mList.destroy();
}

template<class T>
T& Queue<T>::getFirst () {
    LinkedNode<T>* ptrToFirstNode = mList.getFirst();

    if (ptrToFirstNode == (LinkedNode<T>*)0) {
        throw "Queue is empty, can't get first node's value";
    }

    return ptrToFirstNode->mValue;
}

template<class T>
bool Queue<T>::isEmpty () {
    return mList.isEmpty();
}

template<class T>
void Queue<T>::push (T newElement) {
    mList.insertLast(newElement);
}

template<class T>
void Queue<T>::pop () {
    mList.removeFirst();
}
