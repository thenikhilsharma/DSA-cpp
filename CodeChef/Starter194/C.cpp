#include <bits/stdc++.h>
using namespace std;

int profit(vector<int> &arr, int x)
{
  int profit = 0;
  int sold, cake;
  for (int i = 0; i < arr.size(); i++)
  {
    if (x < arr[i])
    {
      sold = x * 50;
    }
    else
    {
      sold = arr[i] * 50;
    }
    cake = x * 30;
    profit += sold - cake;
  }
  return profit;
}

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> cust(n);
    for (int i = 0; i < n; i++)
      cin >> cust[i];

    // binary search on values of x
    int low = *min_element(cust.begin(), cust.end());
    int high = *max_element(cust.begin(), cust.end());
    int max_profit = 0;
    int best_x = 0;

    // finding x that maximizes profit
    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      int current_profit = profit(cust, mid);
      int next_profit = profit(cust, mid + 1);
      int prev_profit = profit(cust, mid - 1);

      if (current_profit >= next_profit && current_profit >= prev_profit)
      {
        max_profit = current_profit;
        best_x = mid;
        break;
      }
      else if (current_profit < next_profit)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    cout << max_profit << endl;
  }

  return 0;
}