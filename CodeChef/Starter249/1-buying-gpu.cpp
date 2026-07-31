// https://www.codechef.com/problems/GPUBUY

#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y, int z) {
    int price = x;
    int coins = 0;
    int months = 0;

    if (z <= y) return -1;
    while (coins < price) {
        price += y;
        coins += z;
        months++;
    }
    
    return months;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        cout << solve(x, y, z) << endl;
    }
    return 0;
}