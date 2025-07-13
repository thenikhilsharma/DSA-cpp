#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

void insertionSort(int n, vector<int> &arr)
{

  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
      if (arr[j] > temp) arr[j + 1] = arr[j]; // shift
      else break;
    }
    // copy temp value
    arr[j + 1] = temp;
  }
}

int main() {
  vector<int> arr = {4, 3, 2, 5, 1};
  int n = arr.size();

  insertionSort(n, arr);
  for (int i: arr) cout << i << " ";
  cout << endl;
}