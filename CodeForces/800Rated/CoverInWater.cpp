#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(string &arr, int n)
  {
    bool has_infinite = false;
    int water = 0;

    // Check for any segment of 3+ consecutive '.'
    for (int i = 0; i < n;)
    {
      if (arr[i] == '.')
      {
        int j = i;
        while (j < n && arr[j] == '.')
          j++;
        if (j - i >= 3)
          has_infinite = true;
        i = j;
      }
      else
        i++;
    }

    if (has_infinite)
    {
      return 2;
    }
    else
    {
      // Count all '.' if no infinite source
      water = count(arr.begin(), arr.end(), '.');
      return water;
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    Solution sol;
    cout << sol.solve(arr, n) << endl;
  }

  return 0;
}

// i need to find 3 consequtive empty cell in order to create an infinite water source
// which require 2 (operation A)
// if 3 consequtive empty cell are not found then sum of empty cell is answer

/*
5
3
...
7
##....#
7
..#.#..
4
####
10
#...#..#.#

*/