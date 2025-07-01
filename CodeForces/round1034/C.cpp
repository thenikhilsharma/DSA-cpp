/* C. Prefix Min and Suffix Max
You are given an array a of distinct integers.

In one operation, you may either:
choose a nonempty prefix of a and replace it with its minimum value, or choose a nonempty suffix of a and replace it with its maximum value.
Note that you may choose the entire array a

For each element ai, determine if there exists some sequence of operations to transform a into [ai]; that is, make the array a consist of only one element, which is ai
Output your answer as a binary string of length n, where the i-th character is 1 if there exists a sequence to transform a into [ai] and 0 otherwise.

A prefix of an array is a subarray consisting of the first k elements of the array, for some integer k
A suffix of an array is a subarray consisting of the last k elements of the array, for some integer k */

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int low = -1000000000008;

void solve(){
     int n;
     cin >> n;
     vector<int>a(n+1),ma(n+1),mi(n+1);
     for(int i = 1;i<=n;i++)cin >>a[i];
     int max_ = INT_MIN,min_ = INT_MAX;
     for(int i = n;i>=1;i--){
        max_ = max(max_,a[i]);
        ma[i] = max_;
     }
     for(int i = 1;i<=n;i++){
        min_ = min(min_,a[i]);
        mi[i] = min_;
     }
     string p;
     for(int i = 1;i<=n;i++){
        if(a[i] == mi[i] || a[i] == ma[i]){
            p += '1';
        }
        else{
            p += '0';
        }
     }
     cout << p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    return 0;
}