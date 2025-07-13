#include<iostream>
using namespace std;

// TC : O(N**2) worst case
// TC : O(N) best case

void bubbleSort(int* arr, int size, int start, int end) {
  if (end <= 0) return;
  if (start < end) {
    if (arr[start] > arr[start+1]) {
      swap(arr[start], arr[start + 1]);
    }
    bubbleSort(arr, size, start+1, end);
  } else bubbleSort(arr, size, 0, end-1);
}

int main() {

  int arr[6] = {10, 18, 1, 6, 14, 9};
  int size = 6;

  bubbleSort(arr, size, 0, size-1);
  for (int &i : arr) cout << i << " ";
  cout << endl;
}