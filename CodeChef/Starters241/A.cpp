#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd = 0, even = 0;
        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            total_sum += a;
            if (a % 2 == 0) even++;
            else odd++;
        }

        if (total_sum % 2 == 0) {
            if (even > 0) cout << "YES\n";
            else cout << "NO\n";
        } else {
            if (odd > 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}