#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] < key) {
      start = mid+1;
    }
    else if (arr[mid] > key) {
      end = mid-1;
    }
    else {
      return mid;
    }
    mid = start + (end - start) / 2;
  }

  return -1;
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};

  cout << binarySearch(arr, 5, 1);
  return 0;
}