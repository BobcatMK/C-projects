#ifndef LINKED_NODE_H
    #define LINKED_NODE_H

    template<typename T>
    struct LinkedNode {
        LinkedNode<T>* mNextNode;
        LinkedNode<T>* mPreviousNode;
        T mValue;
    };
#endif

