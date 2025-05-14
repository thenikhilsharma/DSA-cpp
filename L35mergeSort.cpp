#include<iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high){
  int len1 = mid - low;
  int len2 = high - mid + 1;
  for (int i=low; i<mid; i++){
    if (arr[i] < arr[i+mid])
  }
}

void mergeSort(int* arr, int low, int high){
  if (low >= high){
    return;
  }
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

int main() {
  arr[5] = {3, 2, 4, 1, 3};

  mergeSort(arr, 0, 4)
}