#include<iostream>
using namespace std;

string reverse(string &s, int i, int j){
  while (i<j) swap(s[i++], s[j--]);
  return s;
}

int main() {
  int i = 0, j = 0;
  string s = "this is the word";
  while (j<s.size()){
    if (s[j] == ' '){
      reverse(s, i, j-1);
      i = j+1;
    }
    j++;
  }
  cout << s;
}