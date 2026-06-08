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
#define prt(v)        \
  for (auto i : v)    \
    cout << i << ' '; \
  cout << '\n';
#define sp(n) cout << setprecision(n) << fixed;
#define amax(a, b) (a = max(a, b))
#define amin(a, b) (a = min(a, b))

#ifndef ONLINE_JUDGE
#define debug(x)       \
  cerr << #x << " = "; \
  _print(x);           \
  cerr << endl;
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

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(map<T, V> v);

template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ", ";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

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
typedef unordered_map<ll, ll> umll;

const ll MOD = 1e9 + 7;
const int MAX_N = 500001;
const double PI = 3.14159265358979;

bool revsort(ll a, ll b) { return (a > b); }
void reverseStr(string &str) { reverse(str.begin(), str.end()); }
bool ispal(string x) { return x == string(x.rbegin(), x.rend()); }
int modadd(int a, int b, int m) { return (a % m + b % m) % m; }
int modmul(int a, int b, int m) { return ((ll)a * b) % m; }
int modsub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const long long INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vl arr(n);
    loop(i, 0, n) cin >> arr[i];

    ll ans = INF;

    loop(k, 0, n + 1) {
      bool need_prefix = (k >= 1);
      bool need_suffix = (k < n);

      int a0 = need_prefix ? 0 : 1;
      int b0 = need_suffix ? 0 : 1;

      ll dp00 = INF;
      ll dp01 = INF;
      ll dp10 = INF;
      ll dp11 = INF;

      if (a0 == 0 && b0 == 0) dp00 = 0;
      else if (a0 == 0 && b0 == 1) dp01 = 0;
      else if (a0 == 1 && b0 == 0) dp10 = 0;
      else if (a0 == 1 && b0 == 1) dp11 = 0;

      loop(i, 1, n + 1) {
        ll cost = arr[i - 1];
        ll old00 = dp00;
        ll old01 = dp01;
        ll old10 = dp10;
        ll old11 = dp11;

        ll ndp00 = old00;
        ll ndp01 = old01;
        ll ndp10 = old10;
        ll ndp11 = old11;

        if (i < k) {
          ndp00 = min(ndp00, old00 + cost);
          ndp01 = min(ndp01, old01 + cost);
          ndp10 = min(ndp10, old10 + cost);
          ndp11 = min(ndp11, old11 + cost);
        }
        else {
          ndp10 = min(ndp10, old00 + cost);
          ndp11 = min(ndp11, old01 + cost);
          ndp10 = min(ndp10, old10 + cost);
          ndp11 = min(ndp11, old11 + cost);
        }
        if (i <= k + 1) {
          ndp01 = min(ndp01, old00 + cost);
          ndp01 = min(ndp01, old01 + cost);
          ndp11 = min(ndp11, old10 + cost);
          ndp11 = min(ndp11, old11 + cost);
        }
        else {
          ndp00 = min(ndp00, old00 + cost);
          ndp01 = min(ndp01, old01 + cost);
          ndp10 = min(ndp10, old10 + cost);
          ndp11 = min(ndp11, old11 + cost);
        }

        dp00 = ndp00, dp01 = ndp01, dp10 = ndp10, dp11 = ndp11;
      }

      ans = min(ans, dp11);
    }

    cout << ans << '\n';
  }

  return 0;
}