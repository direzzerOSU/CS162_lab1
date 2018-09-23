// Ryan DiRezze
// CS 162

#ifndef READMATRIX_H
#define READMATRIX_H

class Matrix{
private:
   int size;
   int* array;
public:
   Matrix(int dimensions){
      size = dimensions;
      array = new int[size*size];
   }
};

// class Matrix{
// private:
//    int x=0;
//    int y=0;
//    int** array = new int*[y];
// public:
//    Matrix(int size){
//       for(int i=0; i<y; i++){
//          array[i] = new int[x];
//          for(int c=0; c<x; c++){
//             array[i][c] = 0;
//          }
//       }
//    }
//    void print(); // prints the entire 2D array
//    int get(); // returns the integer at a specific position
//    void freeMemory();
// };
#endif
