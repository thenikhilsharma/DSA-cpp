// https://www.codechef.com/problems/VALLFLAT

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        while(true){
            int idx = -1;
            ll val = -1;
            for(int i = 1; i < n - 1; i++){
                if(a[i] < min(a[i-1], a[i+1])){
                    if(a[i] > val){
                        val = a[i];
                        idx = i;
                    }
                }
            }
            if(idx == -1) break;
            a[idx - 1] = a[idx];
            a[idx + 1] = a[idx];
        }

        ll sum = 0;
        for(auto x : a) sum += x;
        cout << sum << endl;
    }
    return 0;
}