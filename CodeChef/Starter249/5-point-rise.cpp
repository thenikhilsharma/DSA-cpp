// https://www.codechef.com/problems/PTRISMIN

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<ll> x(N);
        for (int i = 0; i < N; i++) cin >> x[i];
        sort(x.begin(), x.end());
        ll ans = INF;

        // Try every pair as the extreme points of level 1
        for (int l = 0; l < N; l++) {
            for (int r = l; r < N; r++) {
                vector<int> id;
                for (int i = 0; i < N; i++)
                    if (i < l || i > r) id.push_back(i);
                if (id.size() < 2) continue;
                int m = id.size();

                // Prefix min/max
                vector<ll> prefMin(m), prefMax(m);
                prefMin[0] = prefMax[0] = x[id[0]];
                for (int i = 1; i < m; i++) {
                    prefMin[i] = min(prefMin[i-1], x[id[i]]);
                    prefMax[i] = max(prefMax[i-1], x[id[i]]);
                }

                // Suffix min/max
                vector<ll> sufMin(m), sufMax(m);
                sufMin[m-1] = sufMax[m-1] = x[id[m-1]];
                for (int i = m-2; i >= 0; i--) {
                    sufMin[i] = min(sufMin[i+1], x[id[i]]);
                    sufMax[i] = max(sufMax[i+1], x[id[i]]);
                }

                for (int cut = 0; cut + 1 < m; cut++) {
                    ll cur = 0;
                    vector<ll> A = {prefMin[cut], prefMax[cut]};
                    vector<ll> B = {x[l], x[r]};
                    vector<ll> C = {sufMin[cut+1], sufMax[cut+1]};

                    for (ll a : A)
                        for (ll b : B)
                            for (ll c : C)
                                cur = max(cur, llabs(2*b - a - c));

                    ans = min(ans, cur);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}