/******************************
** Author: Ryan DiRezze
** Date: September 30, 2018
** Description: Collects and aggregates all source files, which define/implement the
   functions that are used within this file its resulting program. The program does the
   following when running:
      (1) Asks the user for the matrix's (2D array) dimensions,
         which can be either 2x2 or 3x3 (represented as available options for input
         validation).
      (2) Asks the user to input the matrix's integer values, beginning from the top-left
         corner and moves to the right for each row. Once the row's values are input by
         the user, the program moves to the row immediately below the previous row. 
******************************/

// include source file(s) for functions & implementations
#include "readMatrix.hpp"
#include "readMatrix.cpp"
#include "determinant.hpp"
#include "determinant.cpp"

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
