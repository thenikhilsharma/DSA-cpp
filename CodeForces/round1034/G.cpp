#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define f first
#define s second
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 5e5+7;

vector<int> g[MAXN];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fall(i, 2, MAXN)
    for(int j=i; j<MAXN; j += i) g[j].pb(i);

    int tt=1; cin >> tt;

    while(tt--){
        int n, m, q; cin >> n >> m >> q;

        int a[n];

        fall(i, 0, n) cin >> a[i];

        int sum[m+1]; memset(sum, 0, sizeof sum);

        auto upd = [&](int i, int d, int c){
            if(i < 0){ sum[d] += c*(a[0]%d); return; }

            int k=a[i]%d, l=a[i+1]%d;

            int x = (l-k+d)%d;

            sum[d] += c*x;
        };

        for(auto d : g[m])
        fall(i, -1, n-1) upd(i, d, 1);

        while(q--){
            int t; cin >> t;

            if(t == 1){
                int i, v; cin >> i >> v;
                i--;

                for(auto d : g[m]){
                    upd(i-1, d, -1);
                    if(i+1 < n) upd(i, d, -1);
                }

                a[i] = v;

                for(auto d : g[m]){
                    upd(i-1, d, 1);
                    if(i+1 < n) upd(i, d, 1);
                }
            }else{
                int k; cin >> k;

                int l = gcd(k, m);

                if(sum[l] <= m-1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}