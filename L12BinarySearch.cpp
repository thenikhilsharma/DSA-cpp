#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(int arr[], int size, int key){

  int start = 0;
  int end = size - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] < key) start = mid+1;
    else if (arr[mid] > key) end = mid-1;
    else return mid;
  }

  return -1;
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  vector<int> v(arr, arr + 5);

  cout << binarySearch(arr, 5, 1) << endl;

  if (binary_search(v.begin(), v.end(), 3)) {
    cout << lower_bound(v.begin(), v.end(), 3) - v.begin() << endl;
  }
  
  return 0;
}