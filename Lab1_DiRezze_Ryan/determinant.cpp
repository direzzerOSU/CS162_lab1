/******************************
** Program Name: Lab 1
** Author: Ryan DiRezze
** Date: September 30, 2018
** Description: Defines/Implements the "determinant" function, which is calculated based on
   integer values from within a 2D array. This program supports 2x2 and 3x3 2D arrays.
** Inputs (Function Parameters): A (1) double pointer (a pointer that points to pointers)
   and an (2) integer as function parameters.
      (1) The double pointer contains a 2D array, which represents a (2x2 or 3x3) matrix.
      (2) The integer corresponds to the dimensions of the 2D array's matrix.
******************************/

// this implementation file's corresponding header file
#include "determinant.hpp"

// calculates the determinant of the matrix that is passed as a parameter
// of the function (indirectly through pointers)
int determinant(int** matrix, int size){
   // initialize the determinant variable;
   int determinant;

   // 2x2 determinant
   if(size == 2){
      // 2x2 matrix:
      // |a b|
      // |c d|

      // EQUATION (2x2 determinant):
         // determinant = ad - bc

      // initialize variables (mapped to a 2x2 matrix)
      int a = matrix[0][0];
      int b = matrix[0][1];
      int c = matrix[1][0];
      int d = matrix[1][1];

      determinant = (a * d) - (b * c);
   }

   // 3x3 matrix
   else if(size == 3){
      // 3x3 matrix:
         // |a b c|
         // |d e f|
         // |g h i|

      // EQUATION (3x3 determinant):
         // determinant = a(ei - fh) - b(di - fg) + c(dh - eg)

      // initialize variables (mapped to a 3x3 matrix)
      int a = matrix[0][0];
      int b = matrix[0][1];
      int c = matrix[0][2];
      int d = matrix[1][0];
      int e = matrix[1][1];
      int f = matrix[1][2];
      int g = matrix[2][0];
      int h = matrix[2][1];
      int i = matrix[2][2];

      // calculate the determinant from the matrix
      determinant = (a * ((e * i) - (f * h))) - (b * ((d * i) - (f * g))) + (c * ((d * h) - (e * g)));
   }

   // return the determinant (result of the calculation)
   return determinant;
}
