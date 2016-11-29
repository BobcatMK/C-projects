#include <iostream>
#include <string>
#include "Template.h"

using namespace std;

#define WELCOME_MSG cout << "Matrix adding program v1.0"
#define EXPLANATION_1 cout << "In this program you can add two matrices, and the result is printed out in third matrix"
#define EXPLANATION_2 cout << "You can type how should matrix's dimension look like" 
#define EXPLANATION_3 cout << "For example it can be 2x3 or 10x1 - it's up to you"

int main() {
  // matrix variables declarations

  int Array_1D_size = 0;
  int Array_2D_size = 0;
  Table<int>* A = new Table<int>();
  Table<int>* B = new Table<int>();
  Table<int>* C = new Table<int>();
  int tempHolder;
  bool quit = false;
  char quitDecision = '\0';

  do {
    WELCOME_MSG << endl;
    EXPLANATION_1 << endl;
    EXPLANATION_2 << endl;
    EXPLANATION_3 << endl;

    // creating matrix with user input size
    cout << "State matrices first dimension size: ";
    cin >> Array_1D_size;
    cout << endl;

    cout << "Matrices second dimension size: ";
    cin >> Array_2D_size;
    cout << endl;

    A->resize(Array_1D_size, Array_2D_size);
    B->resize(Array_1D_size, Array_2D_size);
    C->resize(Array_1D_size, Array_2D_size);

    for (int i = 0 ; i < Array_1D_size ; ++i) {
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        cout << "A[" << i << "][" << j << "] = ";
        cin >> tempHolder;
        // A->changeValue(i,j,tempHolder);
        (*A)(i, j, tempHolder);
        cout << endl;
      }
    }

    for (int i = 0 ; i < Array_1D_size ; ++i) {
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        cout << "B[" << i << "][" << j << "] = ";
        cin >> tempHolder;
        B->changeValue(i,j,tempHolder);
        cout << endl; 
      }    
    }

    for (int i = 0 ; i < Array_1D_size ; ++i) {
      unsigned long holder_C = 0;
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        C->changeValue(i, j, (*A)(i, j) + (*B)(i, j));
      }
    }

    // showing results the way it meant to be shown in the exercise
    // matrix A results
    cout << endl;
    cout << "A =";
    for (int i = 0 ; i < Array_1D_size ; ++i) {
      cout << endl;
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        cout << " " << (*A)(i, j) << " ";
      }
    }
    cout << endl;
    cout << "B =";
    for (int i = 0 ; i < Array_1D_size ; ++i) {
      cout << endl;
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        cout << " " << (*B)(i, j) << " ";
      }      
    }
    cout << endl;
    cout << "C =";
    for (int i = 0 ; i < Array_1D_size ; ++i) {
      cout << endl;
      for (int j = 0 ; j < Array_2D_size ; ++j) {
        cout << " " << (*C)(i, j) << " ";
      }      
    }
    cout << endl << endl;

    cout << endl << "Do you want to quit? ";
    cin >> quitDecision;
    cout << endl;

    if (quitDecision == 'y' || quitDecision == 'Y')
      quit = true;
  } while (!quit);

  // delete dynamically allocated memory
  delete A;
  delete B;
  delete C;
}
