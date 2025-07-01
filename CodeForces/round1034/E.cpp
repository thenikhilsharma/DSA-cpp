#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define nl '\n'
#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define loopr(i, a, b) for (int i = (b); i >= (a); --i)
#define prt(v) for (auto i : v) cout << i << ' '; cout << '\n';
#define sp(n) cout << setprecision(n) << fixed;
#define amax(a, b) (a = max(a, b))
#define amin(a, b) (a = min(a, b))

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(map<T, V> v);

template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxh;
typedef priority_queue<int, vi, greater<int>> minh;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef unordered_map<int, int> umii;

const ll MOD = 1e9 + 7;
const int MAX_N = 500001;
const double PI = 3.14159265358979;
const ll INF = 1e15;

bool revsort(ll a, ll b) { return (a > b); }
void reverseStr(string &str) { reverse(str.begin(), str.end()); }
bool ispal(string x) { return x == string(x.rbegin(), x.rend()); }
int modadd(int a, int b, int m) { return (a % m + b % m) % m; }
int modmul(int a, int b, int m) { return ((ll)a * b) % m; }
int modsub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll expo(ll a, ll n, ll m) {
    ll res = 1;
    while (n) {
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
            for (int j = 2 * i; j <= maxN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

long long power(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    ll n;
    cin >> n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    map<int,int>mpp;
    loop(i,0,n) mpp[a[i]]=0;
    loop(i,0,n) mpp[a[i]]++;

    vector<int>ans(n+2);
    for(int i=0;i<=n;i++){
        ans[mpp[i]]++;
        ans[n-i+1]--;
        if(mpp[i]==0){
            break;
        }
    }
    for(int i=1;i<n+1;i++){
        ans[i]+=ans[i-1];
    }
    for(int i=0;i<n+1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}