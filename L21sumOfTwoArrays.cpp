#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int addition(vector<int> &arr1, vector<int> &arr2){
  int i = arr1.size() - 1, j = arr2.size() - 1;
  int res = 0, carry = 0, temp = 0, multiplier = 1;
  
  while (i >= 0 || j >= 0 || carry) {
    int digit1 = (i >= 0) ? arr1[i--] : 0;
    int digit2 = (j >= 0) ? arr2[j--] : 0;

    temp = digit1 + digit2 + carry;
    carry = temp / 10;
    res += (temp % 10) * multiplier;
    multiplier *= 10;
  }

  return res;
}

int main(){
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {9, 9};
  cout << addition(arr1, arr2);
}