#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define loop(i, a, b) for (int i = (a); i < (b); i++)

typedef vector<int> vi;

int modmul(int a, int b, int m) { return ((ll)a * b) % m; }

ll expo(ll a, ll n, ll m) {
    ll res = 1;
    while (n)
    {
        if (n & 1) res = modmul(res, a, m);
        a = modmul(a, a, m);
        n >>= 1;
    }
    return res;
}

vi primes;
void init(int maxN) {
    vi is_prime(maxN + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = 2 * i; j <= maxN; j += i) is_prime[j] = 0;
        }
    }
}

ll power(ll base, ll exp, int mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll n;
    cin >> n;
    vi a(n);
    loop(i, 0, n) cin >> a[i];
    map<int, int> mpp;
    loop(i, 0, n) mpp[a[i]] = 0;
    loop(i, 0, n) mpp[a[i]]++;

    vector<int> ans(n + 2);
    for (int i = 0; i <= n; i++) {
        ans[mpp[i]]++;
        ans[n - i + 1]--;
        if (mpp[i] == 0) break;
    }
    loop(i, 1, n + 1) ans[i] += ans[i - 1];
    loop(i, 0, n + 1) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}