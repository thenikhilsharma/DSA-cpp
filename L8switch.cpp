#include <iostream>
using namespace std;

int main()
{
  int n = 2;
  char c = '1';
  int d = 0;

  switch (n)
  {
  case '1':
    cout << "this is case 1" << endl;
    break;

  case 2:
    cout << "this is case 2" << endl;
    break;

  default:
    cout << "this is default" << endl;
  }
}