#include <bits/stdc++.h>
using namespace std;

// TC : O(Nlog(N))
// SC : O(1)

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;
  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) i++;
    while (arr[j] > pivot && j >= low + 1) j--;
    if (i < j) swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex+1, high);
  }
}

int main() {

  vector<int> arr = {5, 2, 4, 3, 1};
  quickSort(arr, 0, arr.size()-1);
  for (int i: arr) cout << i << " ";
  cout << endl;

  return 0;
}