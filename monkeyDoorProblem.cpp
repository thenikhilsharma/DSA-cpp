#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<bool> func(int n)
{
  int i = 2;
  vector<bool> doors(n, 0);
  while (i <= n)
  {
    for (int j = 1; j <= n; j++)
    {
      if (j % i == 0)
        doors[j] = doors[j] == 1 ? 0 : 1;
    }
    i++;
  }
  return doors;
}

print(vector<bool> &doors)
{
  for (int i=0; i < doors.size(); i++)
  {
    if (doors[i] == 0) cout << i << endl;
  }
}

int main()
{
  int n = 100;
  vector<bool> doors(n);
  doors = func(n);
  print(doors);
}
