#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int high, int mid) {
  int i=low, j=mid+1;
  vector<int> temp;
  while (i <= mid && j <= high) {
    if (arr[i] > arr[j]) temp.push_back(arr[j++]);
    else temp.push_back(arr[i++]);
  }

  while (i <= mid) temp.push_back(arr[i++]);
  while (j <= high) temp.push_back(arr[j++]);

  for (int k=low; k<=high; k++) arr[k] = temp[k - low];
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low == high) return;

  int mid = low + (high - low) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, high, mid);
}

int main() {
  
  vector<int> arr = {2, 4, 5, 1, 3};
  mergeSort(arr, 0, arr.size()-1);

  for (auto i: arr) cout << i << " ";
  cout << endl;
}