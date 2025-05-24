#include<iostream>
using namespace std;

int main() {
  char c = 20;
  cout << "not of c is: " << ~c << endl; // NOT operator
  cout << "left shift is: " << (c<<1) << endl; // Left shift operator (multiply by 2*1)
  cout << "right shift is: " << (c>>2) << endl; // right shift operator (divide by 2*2)
}