/******************************
** Program Name: Lab 1
** Author: Ryan DiRezze
** Date: September 30, 2018
** Description: Defines/Implements two functions that:
     (1) readMatrix: Requests user input
         for each value within the 2D array that's passed as a function parameter
         (as a double pointer), and updates values within the 2D array. Based on the integer,
         which is passed as a function parameter as 'size', readMatrix requests input for either
         a 2x2 or 3x3 2D array.
     (2) printMatrix: Prints the 2D array that is passed as a function parameter.
         printMatrix prints the 2D array (matrix) as it would normally appear across
         two dimensions (x and y axes).
** Inputs (Function Parameters): Function parameters are identical for both functions that
   are defined/implemented within this file.
     (1) Double pointer of integers (pointer to pointers) that contains 2D array (matrix)
         values.
     (2) Integer for 'size' that represents the number of positions, which contain integer
         values, across each axis within the 2D array (matrix) - x and y axes.
******************************/

// this implementation file's corresponding header file
#include "readMatrix.hpp"

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;

// TODO: Input Validation function(s)
// TODO: Build makefile

// based on the 'size' function parameter, this function requests user input for
// each value/position within the corresponding matrix (2x2/3x3 based on 'size'),
// then updates the matrix that is passed as a function parameter (indirectly through pointers)
void readMatrix(int** matrix, int size){
   cout << endl << "Please enter all integers within the matrix, beginning\nfrom top to bottom and left to right:" << endl << endl;
   for(int r=0; r<size; r++){
      for(int c=0; c<size; c++){
         cout << "Value at matrix[" << r << "][" << c << "]: ";
         cin >> matrix[r][c];
      }
   }
}

// prints the matrix that is indirectly passed (via pointers) as a function parameter
void printMatrix(int** matrix, int size){
   cout << endl << "Matrix:" << endl;
   for(int r=0; r<size; r++){
      for(int c=0; c<size; c++){
         cout << matrix[r][c];
      }
      cout << endl;
   }
}
