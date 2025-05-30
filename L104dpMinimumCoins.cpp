#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int> &num, int x){
  // base case
  if (x==0) return 0;
  if (x < 0) return __INT_MAX__;

  // recursion
  int mini = INT_MAX;
  for (int i=0; i<num.size(); i++){
    int ans = solve(num, x-num[i]);
    if(ans != __INT_MAX__) mini = min(mini, 1+ans);
  }
  return mini;
}

int main(){
  vector<int> num = {1,2,3};
  int x = 11;
  int ans = solve(num, x);
  if (ans == __INT_MAX__) ans = -1;
  cout << ans;
}