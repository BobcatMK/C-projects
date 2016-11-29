#include <iostream>
#include "LinkedList.h"
#include "LinkedNode.h"
#include "libraries/helpers/helpers.cpp"

using namespace std;


template<typename T>
LinkedList<T>::LinkedList () : mFirst(0), mLast(0) {}

template<typename T>
LinkedList<T>::LinkedList (LinkedList<T>& rhs) {
    mFirst = 0;
    mLast = 0;
    if (rhs.isEmpty()) {
        mFirst = 0;
        mLast = 0;
        return;
    }

    LinkedNode<T>* currentlyLookingAt = rhs.getFirst();
    while (true) {
        insertLast(currentlyLookingAt->mValue);
        if (currentlyLookingAt->mNextNode) {
            currentlyLookingAt = currentlyLookingAt->mNextNode;
        } else {
            break;
        }
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator= (LinkedList<T>& rhs) {
    destroy();
    if (rhs.isEmpty()) {
        mFirst = 0;
        mLast = 0;
        return *this;
    }

    LinkedNode<T>* currentlyLookingAt = rhs.getFirst();
    while (true) {
        insertLast(currentlyLookingAt->mValue);
        if (currentlyLookingAt->mNextNode) {
            currentlyLookingAt = currentlyLookingAt->mNextNode;
        } else {
            break;
        }
    }
    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList () {
    this->destroy();
}

template<typename T>
bool LinkedList<T>::isEmpty () {
    return mFirst == 0 && mLast == 0;
}

template<typename T>
LinkedNode<T>* LinkedList<T>::getFirst () {
    return mFirst;
}

template<typename T>
LinkedNode<T>* LinkedList<T>::getLast () {
    return mLast;
}

template<typename T>
void LinkedList<T>::insertFirst (T data) {
    LinkedNode<T>* pointerToPreviouslyFirst = mFirst;

    if (pointerToPreviouslyFirst == 0) {
        // it means that linked list is empty and we are inserting first element
        mFirst = new LinkedNode<T>();
        mLast = mFirst;
        mFirst->mNextNode = 0;
        mFirst->mPreviousNode = 0;
        mFirst->mValue = data;
        return;
    }

    mFirst = new LinkedNode<T>();
    mFirst->mNextNode = pointerToPreviouslyFirst;
    mFirst->mPreviousNode = 0;
    mFirst->mValue = data;

    pointerToPreviouslyFirst->mPreviousNode = mFirst;
}

template<typename T>
void LinkedList<T>::insertLast (T data) {
    LinkedNode<T>* pointerToPreviouslyLast = mLast;

    if (pointerToPreviouslyLast == 0) {
        // it means that linked list is empty and we are inserting first element
        mLast = new LinkedNode<T>();
        mFirst = mLast;
        mLast->mNextNode = 0;
        mLast->mPreviousNode = 0;
        mLast->mValue = data;
        return;
    }

    mLast = new LinkedNode<T>();
    mLast->mNextNode = 0;
    mLast->mPreviousNode = pointerToPreviouslyLast;
    mLast->mValue = data;

    pointerToPreviouslyLast->mNextNode = mLast;
}

template<typename T>
void LinkedList<T>::insertAfter (T tKey, T tData) {
    if (mFirst == 0 && mLast == 0) {
        // no elements: can't add after element that does not exist
        ONE_SPACE
        cout << "Error: can't insert after element is linked list is empty";
        ONE_SPACE
        return;
    }

    LinkedNode<T>* currentLookingAt = mFirst;
    bool found = false;
    while (found == false) {
        if (currentLookingAt->mValue == tKey) {
            found = true;
            break;
        }

        if (currentLookingAt->mNextNode == 0) {
            found = false;
            break;
        }

        currentLookingAt = currentLookingAt->mNextNode;
    }

    if (found) {
        LinkedNode<T>* nextAfterFoundNode = currentLookingAt->mNextNode;
        LinkedNode<T>* newNode = new LinkedNode<T>();
        newNode->mPreviousNode = currentLookingAt;
        newNode->mNextNode = nextAfterFoundNode;
        newNode->mValue = tData;

        // adjust next and previous pointers of next and previous list nodes - according to newNode
        currentLookingAt->mNextNode = newNode;
        if (nextAfterFoundNode != 0) {
            nextAfterFoundNode->mPreviousNode = newNode;
        } else if (nextAfterFoundNode == 0) {
            mLast = newNode;
        }
    } else {
        ONE_SPACE
        cout << "Error: the element you are trying to insert after does not exist";
        ONE_SPACE
    }
}

template<typename T>
void LinkedList<T>::removeFirst () {
    if (!mFirst && !mLast) {
        ONE_SPACE
        cout << "Error: sorry can't remove first element if linked list is empty";
        ONE_SPACE
    }

    if (mFirst == mLast) {
        // it means that linked list has only one element
        delete mFirst;
        mFirst = 0;
        mLast = 0;
        return;
    }

    LinkedNode<T>* nextAfterFirst = mFirst->mNextNode;

    delete mFirst;
    mFirst = nextAfterFirst;
    mFirst->mPreviousNode = 0;
}

template<typename T>
void LinkedList<T>::removeLast () {
    if (!mLast && !mFirst) {
        // it means that linked list is empty
        ONE_SPACE
        cout << "Error: sorry can't remove first element if linked list is empty";
        ONE_SPACE
    }

    if (mLast == mFirst) {
        delete mLast;
        mFirst = 0;
        mLast = 0;
        return;
    }

    LinkedNode<T>* previousBeForeLast = mLast->mPreviousNode;

    delete mLast;
    mLast = previousBeForeLast;
    mLast->mNextNode = 0;
}

template<typename T>
void LinkedList<T>::remove (T removalCandidate) {
    if (!mFirst && !mLast) {
        // linked list is empty can't delete
        ONE_SPACE
        cout << "Error: can't remove element from empty linked list";
        ONE_SPACE
    }

    LinkedNode<T>* currentlyLookingAt = mFirst;

    bool found = false;
    while (found == false) {
        if (currentlyLookingAt->mValue == removalCandidate) {
            found = true;
            break;
        }

        if (currentlyLookingAt->mNextNode == 0) {
            found = false;
            break;
        }

        currentlyLookingAt = currentlyLookingAt->mNextNode;
    }

    if (found) {
        LinkedNode<T>* nextAfterFoundNode = currentlyLookingAt->mNextNode;
        LinkedNode<T>* previousBeforeFoundNode = currentlyLookingAt->mPreviousNode;

        if (mFirst == mLast) {
            mFirst = 0;
            mLast = 0;
            return;
        } else if (currentlyLookingAt == mFirst) {
            mFirst = nextAfterFoundNode;
            mFirst->mPreviousNode = 0;
            return;
        } else if (currentlyLookingAt == mLast) {
            mLast = previousBeforeFoundNode;
            mLast->mNextNode = 0;
            return;
        }

        delete currentlyLookingAt;

        if (nextAfterFoundNode) {
            nextAfterFoundNode->mPreviousNode = previousBeforeFoundNode;
            return;
        }
        if (previousBeforeFoundNode) {
            previousBeforeFoundNode->mNextNode = nextAfterFoundNode;
            return;
        }
    } else {
        ONE_SPACE
        cout << "Error: the element you are trying to delete does not exist";
        ONE_SPACE
    }
}

template<typename T>
void LinkedList<T>::destroy () {
    if (!mFirst && !mLast) {
        return;
    }

    LinkedNode<T>* currentlyLookingAt = mFirst;
    LinkedNode<T>* nextAfterCurrent = mFirst->mNextNode;
    while (true) {
        delete currentlyLookingAt;
        if (nextAfterCurrent) {
            currentlyLookingAt = nextAfterCurrent;
            nextAfterCurrent = currentlyLookingAt->mNextNode;
        } else {
            mFirst = 0;
            mLast= 0;
            break;
        }
    }
}
