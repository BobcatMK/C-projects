#include <iostream>
#include <vector>

using namespace std;


template<typename T, class U>
void for_each (T arrayPassed[], int arraySize, U functor) {
    for (int i = 0; i < arraySize; i++) {
        functor(arrayPassed[i]);
    }
}

template<typename T>
int count (T arrayPassed[], int arraySize, T elementToCount) {
    int counter = 0;

    for (int i = 0; i < arraySize; i++) {
        if (arrayPassed[i] == elementToCount) {
            counter++;
        }
    }

    return counter;
}

template<typename T>
void reverse (T arrayPassed[], int arraySize) {
    T* reversedArray = new T[arraySize];

    for (int i = 0, j = arraySize - 1; i < arraySize; i++, j--) {
        reversedArray[i] = arrayPassed[j];
    }

    for (int i = 0; i < arraySize; i++) {
        arrayPassed[i] = reversedArray[i];
    }

    delete[] reversedArray;
}

template<typename T>
void sort (T arrayPassed[], int arraySize) {
    T tempHolder;
    for (int i = 0; i < arraySize; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (arrayPassed[i] > arrayPassed[j]) {
                tempHolder = arrayPassed[i];
                arrayPassed[i] = arrayPassed[j];
                arrayPassed[j] = tempHolder;
            }
        }
    }
}
