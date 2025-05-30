#include <iostream>
#include<vector>
using namespace std;

// int fibonacii(int n)
// {
//   if (n == 0 || n == 1)
//   {
//     return n;
//   }
//   return fibonacii(n - 1) + fibonacii(n - 2);
// }

int fibonacii(int n, vector<int> &dp)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  dp[n] = fibonacii(n - 1, dp) + fibonacii(n - 2, dp);
  return dp[n];
}

int main()
{
  int n = 6;
  vector<int> dp(n + 1, -1);
  cout << fibonacii(n, dp);
}