#define loop(i, a, b) for (int i = (a); i < (b); ++i)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        loop(i, 0, n) cin >> a[i];
        
        vector<int> previous_different(n, -1);
        int prv = -1;
        loop(i, 1, n) {
          if (a[i] != a[i-1]) prv = i-1;
          previous_different[i] = prv;
        }

        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            if (previous_different[r-1] >= l-1) {
              cout << r << " " << previous_different[r-1] + 1 << endl;
            }
            else cout << -1 << " " << -1 << endl;
        }
        cout << endl;
    }
    return 0;
}