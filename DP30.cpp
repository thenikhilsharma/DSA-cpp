#include<bits/stdc++.h>
using namespace std;

// minimum operations to convert string A to string B
int check(string &text1, string &text2)
{
  int m = text1.length(), n = text2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = m - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (text1[i] == text2[j])
      {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      }
      else
      {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  return dp[0][0];
}

int main(){
  string s1 = "abcd";
  string s2 = "anc";
  int maxm = s1.length() + s2.length();
  int ans = maxm - 2*check(s1, s2);
  cout << ans;
}