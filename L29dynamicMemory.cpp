#include<iostream>
using namespace std;

// 2D array creation
int main() {

  int row = 3;
  int col = 4;

  int **arr = new int *[row];

  for (int i=0; i<n; i++) {
    arr[i] = new int[col];
  }

  //input
  for(int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
      cin >> arr[i][j];
    }
  }

  // releasing memory
  for(int i=0; i<row; i++) {
    delete [] arr[i];
  }

  delete []arr;
}