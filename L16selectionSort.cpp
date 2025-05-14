#include<iostream>
using namespace std;

void selectionSort(int* arr, int size){ // O(n^2), use when array size is small
  int i = 0;
  int temp, min;
  while (i < size) {
    min = i;
    for (int j=i; j<size; j++){
      if (arr[j] < arr[i] && arr[j] < arr[min]){
        min = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    i++;
  }
}

int main() {

  int arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};
  int size = 9;

  selectionSort(arr, size);

  int i = 0;
  while (i < size){
    cout << arr[i] << "--";
    i++;
  }
}