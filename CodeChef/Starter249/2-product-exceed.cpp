// https://www.codechef.com/problems/PRDEXC

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int x, y, p;
	    cin >> x >> y >> p;
	    int cnt = 0;
	    while (x*y < p) {
	        cnt++;
	        if (x <= y) x++;
            else y++;
	    }
	    cout << cnt << endl;
	}
}