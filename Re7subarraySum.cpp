#include <iostream>
#include <vector>
using namespace std;

void recurr(int index, vector<int> &arr, vector<int> &curr, int sum, int n, vector<vector<int>> &ans)
{
  if (index == arr.size())
  {
    if (sum == n)
    {
      ans.push_back(curr);
    }
    return;
  }

  // Take the current element
  curr.push_back(arr[index]);
  recurr(index + 1, arr, curr, sum + arr[index], n, ans);
  curr.pop_back();
  // Do not take the current element
  recurr(index + 1, arr, curr, sum, n, ans);
}

void print(vector<vector<int>> &ans)
{
  for (auto &i : ans)
  {
    for (auto &j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<int> arr = {2,3,6,7};
  vector<vector<int>> ans;
  vector<int> curr;
  recurr(0, arr, curr, 0, 7, ans);
  print(ans);
}