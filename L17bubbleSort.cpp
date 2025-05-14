#include<iostream>
using namespace std;

void swap(int* arr, int first, int second){
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

void printarr(int arr[], int size){
  int i = 0;
  while(i < size){
    cout << arr[i] << "-";
    i++;
  }
}

void bubbleSort(int* arr, int size, int i, int j){
  while (j--){
    if (i < size - 1){
      if (arr[i] > arr[i+1]){
        swap(arr, i, i+1);
      }
      bubbleSort(arr, 6, i+1, j);
    }
  }
}

int main() {

  int arr[6] = {10, 18, 1, 6, 14, 9};
  int size = 6;

  bubbleSort(arr, size, 0, size-1);
  printarr(arr, 6);
}