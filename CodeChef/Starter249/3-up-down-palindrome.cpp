// https://www.codechef.com/problems/UPDWPAL

#include <bits/stdc++.h>
using namespace std;
// #define long long ll

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> A(n+1);
        for(auto &ch:A) cin >> ch;

        bool possible = true;
        long long lo = LLONG_MIN, hi = LLONG_MAX;

        for(int i = 1, j = n; i < j; i++, j--){
            long long a = A[i], b = A[j];
            if(a == b) continue;

            long long diff = llabs(a - b);
            if(diff != 2){
                possible = false;
                break;
            }
            long long mn = min(a, b);
            lo = max(lo, mn);
            hi = min(hi, mn + 1);
        }

        if(possible && lo <= hi) cout << "Yes\n";
        else cout << "NO\n";
    }
    return 0;
}