#include "LinkedNode.h"

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H
    template<typename T>
    class LinkedList {
        public:
            LinkedList();
            ~LinkedList();
            LinkedList(LinkedList<T>& rhs);
            LinkedList<T>& operator=(LinkedList<T>& rhs);

            bool isEmpty();
            LinkedNode<T>* getFirst();
            LinkedNode<T>* getLast();

            void insertFirst(T data);
            void insertLast(T data);
            void insertAfter(T tKey, T tData);
            void removeFirst();
            void removeLast();
            void remove(T removalCandidate);
            void destroy();
        private:
            LinkedNode<T>* mFirst;
            LinkedNode<T>* mLast;
    };
#endif
