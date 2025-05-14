#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

  int start = 0;
  int end = size - 1;
  int mid = end / 2;

  while (arr[mid] != key) {
    mid = (start + end) / 2;
    if (arr[mid] < key) {
      start = mid;
    }
    else if (arr[mid] > key) {
      end = mid;
    }
  }

  return mid;
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int key;

  cout << binarySearch(arr, 5, 2);
  return 0;
}