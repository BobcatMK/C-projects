#include <iostream>

using namespace std;

#ifndef ARRAY_H
    #define ARRAY_H

    template <typename T>
    class Array {
        public:
            // Create a Array with zero elements.
            Array();
            // Create a Array with 'size' elements.
            Array(int size);
            // Create a Array from another Array--
            // be sure to prevent memory leaks!
            Array(Array<T>& rhs);
            // Free dynamic memory.
            ~Array();
            // Define how a Array shall be assigned to
            // another Array--be sure to prevent memory
            // leaks!
            Array<T>& operator=(Array<T>& rhs);
            // Resize the Array to a new size.
            void resize(int newSize);
            // Return the number of elements in the array.
            int size();
            // Overload bracket operator so client can index
            // into Array objects and access the elements.
            T& operator[](int i);
            void print(Array<T>& fa);
            void print();
        private:
            T* mData; // Pointer to array of Ts (dynamic memory).
            int mSize; // The number of elements in the array.
    };

    template <typename T>
    Array<T>::Array() {
        mData = new T[0];
        mSize = 0;
    }

    template <typename T>
    Array<T>::Array(int size) {
        mData = new T[size];
        mSize = size;
    }

    template <typename T>
    Array<T>::Array(Array<T>& rhs) {
        mSize = rhs.size();
        mData = new T[mSize];
        
        for (int i = 0; i < mSize; i++) {
            mData[i] = rhs[i];
        }
    }

    template <typename T>
    Array<T>::~Array() {
        delete[] mData;
    }

    template <typename T>
    Array<T>& Array<T>::operator=(Array<T>& rhs) {
        if (this == &rhs) {
            return rhs;
        }

        delete[] mData;
        mSize = rhs.size();
        mData = new T[mSize];

        for (int i = 0; i < mSize ; i++) {
            mData[i] = rhs[i];
        }

        return rhs;
    }

    template <typename T>
    void Array<T>::resize(int newSize) {
        T* dynArray = new T[newSize];

        for (int i = 0; i < newSize; i++) {
            if (i <= mSize)
                dynArray[i] = mData[i];
            else
                dynArray[i] = T();
        }

        mSize = newSize;
        delete[] mData;
        mData = dynArray;
    }

    template <typename T>
    int Array<T>::size() {
        return mSize;
    }

    template <typename T>
    T& Array<T>::operator[](int i) {
        return mData[i];
    }

    template <typename T>
    void Array<T>::print(Array<T>& fa) {
        // insertion operator needs to be overloaded for custom variable types to work
        cout << "{ ";
        for(int i = 0; i < fa.size(); ++i)
        cout << fa[i] << " ";
        cout << "}" << endl << endl;
    }

    template <typename T>
    void Array<T>::print() {
        // insertion operator needs to be overloaded for custom variable types to work
        cout << "{ ";
        for(int i = 0; i < mSize; ++i)
            cout << mData[i] << " ";
        cout << "}" << endl << endl;
    }

#endif
