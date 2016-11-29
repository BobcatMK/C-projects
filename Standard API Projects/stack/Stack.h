#include "libraries/linked_list/LinkedList.h"

#ifndef STACK_H
    #define STACK_H

    template<typename T>
    class Stack {
        public:
            Stack();
            ~Stack();
            T& getTopItem();

            bool isEmpty(void);
            void push(T newElement);
            void pop();

        private:
            LinkedList<T> mList;
    };
#endif
