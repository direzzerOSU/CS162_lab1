#include "readMatrix.hpp"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;

// function prototypes
void readMatrix(int** matrix, int size);
void printMatrix(int** matrix, int size);
int determinant(int** matrix, int size);

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

int main(){
   // adds a blank line before program content for formatting/aesthetics
   cout << endl;
   // prompt the user for matrix size selection & user input
   char selection;
   int dim;
   do{
      cout << "Please select the size of your two-dimensional (2D) array:" << endl;
      cout << "a. 2x2" << endl;
      cout << "b. 3x3" << endl;
      cin >> selection;
      if(tolower(selection) == 'a'){
         dim = 2;
      }
      else if(tolower(selection) == 'b'){
         dim = 3;
      }
      else{
         cout << "Uh oh! That's not a valid option... Please try again." << endl;
      }
   } while(tolower(selection) != 'a' && tolower(selection) != 'b');

   // initialize size & the pointer to a pointer
   const int size = dim;
   int** matrix = new int*[size];   // create a pointer to dynamic pointers

   for(int r=0; r<size; r++){
      matrix[r] = new int[size];    // build rows for each pointer within the parent pointer
   }

   readMatrix(matrix, size);
   printMatrix(matrix, size);
   cout << endl << "determinant: " << determinant(matrix, size) << endl;

   // free the dynamically allocated memory
   for(int r=0; r<size; r++){
      delete[] matrix[r];
   }
   delete[] matrix;

   return 0;
}
