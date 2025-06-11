#include<iostream>
using namespace std;

bool palindrome(string &s){
  int low = 0, high = s.size()-1;
  while (low <= high){
    if (s[low] != s[high]) return false;
    low++, high--;
  }
  return true;
}

int main() {
  string s = "hiohhoih";
  string s2 = "ohno";
  cout << palindrome(s) << " and " << palindrome(s2);
}