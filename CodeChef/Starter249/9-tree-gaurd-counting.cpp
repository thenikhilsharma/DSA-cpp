// https://www.codechef.com/problems/TREEGUARD2

#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#ifndef ONLINE_JUDGE
#include <debug_algo/local_debug.h>
#else
#define dbg(...) 555
#define dbgline(...) 555
#endif

#define endl '\n'
#define all(x) begin(x), end(x)
#define fst first
#define snd second
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

namespace Varialbles {
	template<typename T> constexpr T inf;
	template<> constexpr int inf<int> = 0x3f3f3f3f;
	template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
};
using namespace Varialbles;

namespace Functions {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	inline int rnd(int a, int b) {
		return rng() % (b - a + 1) + a;
	}

	template<typename T, typename U> inline bool chkmin(T& x, U y) {
		if (y < x) return x = y, true; return false;
	}
	template<typename T, typename U> inline bool chkmax(T& x, U y) {
		if (y > x) return x = y, true; return false;
	}
	template<typename T> T floor(T a, T b) {
		assert(b > 0);
		return a / b - (a < 0 && a % b != 0);
	}
	template<typename T> T ceil(T a, T b) {
		assert(b > 0);
		return floor(a - 1, b) + 1;
	}
	template<typename T> vector<T> operator += (vector<T> &a, int val){
		for(auto &i: a) i += val; return a;
	}
	template<typename T>
	vector<int> argsort(const vector<T> &A) {
	    vector<int> idx(len(A));
	    iota(all(idx), 0);
	    sort(all(idx), [&](int i, int j) { return A[i] < A[j]; });
	    return idx;
	}
	template <typename T, typename... Vectors>
	void concat(vector<T> &first, const Vectors &...others) {
	    vector<T> &res = first;
	    (res.insert(res.end(), others.begin(), others.end()), ...);
	}
};
using namespace Functions;

namespace IO {
	vector<vector<int>> read_graph(int n, int m, int base = 0) {
		vector<vector<int>> g(n+base);
		for(int i = 0; i < m; i ++) {
			int u, v; cin >> u >> v;
			u -= 1 - base;
			v -= 1 - base;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		return g;
	}
	vector<vector<int>> read_tree(int n, int base = 0) {
		return read_graph(n, n-1, base);
	}
    template <class S, class T>
    auto &operator>>(istream &ist, pair<S, T> &d) {
        return ist >> d.first >> d.second;
    }
    template <class T>
    auto &operator>>(istream &ist, vector<T> &d) {
        for (auto &e : d)
            ist >> e;
        return ist;
    }
    template <class T, size_t S>
    auto &operator>>(istream &ist, array<T, S> &d) {
        for (auto &e : d)
            ist >> e;
        return ist;
    }
	template<typename T, typename S>
	auto &operator << (ostream& ost, const pair<T,S> &p) {
		return ost << p.first << ' ' << p.second;
	}
    template <class T>
    auto &operator<<(ostream &ost, vector<T> &d) {
        for (auto it = d.begin(); it != d.end(); it++) {
            if (it + 1 == d.end())
                ost << *it;
            else
                ost << *it << ' ';
        }
        return ost;
    }
};
using namespace IO;


namespace ModNumber {
	template<class T> constexpr T power(T a, long long b) {
	    T res = 1;
	    for (; b; b /= 2, a *= a) if (b % 2) res *= a;
	    return res;
	}
	 
	template<int P>
	struct MInt {
	    int x;
	    constexpr MInt() : x{} {}
	    constexpr MInt(long long x) : x{norm(x % getMod())} {}
	    
	    static int Mod;
	    constexpr static int getMod() { if (P > 0) return P; else return Mod; }
	    constexpr static void setMod(int Mod_) { Mod = Mod_; }
	    constexpr int norm(int x) const { if (x < 0) x += getMod(); if (x >= getMod()) x -= getMod(); return x; }
	    constexpr int val() const { return x; }
	    explicit constexpr operator int() const { return x; }
	    constexpr MInt operator-() const { MInt res; res.x = norm(getMod() - x); return res; }
	    constexpr MInt inv() const { assert(x != 0); return power(*this, getMod() - 2); }
	    constexpr MInt &operator*=(MInt rhs) & { x = 1LL * x * rhs.x % getMod();return *this; }
	    constexpr MInt &operator+=(MInt rhs) & { x = norm(x + rhs.x); return *this; }
	    constexpr MInt &operator-=(MInt rhs) & { x = norm(x - rhs.x); return *this; }
	    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
	    friend constexpr MInt operator*(MInt lhs, const MInt& rhs) { return lhs *= rhs; }
	    friend constexpr MInt operator+(MInt lhs, const MInt& rhs) { return lhs += rhs; }
	    friend constexpr MInt operator-(MInt lhs, const MInt& rhs) { return lhs -= rhs; }
	    friend constexpr MInt operator/(MInt lhs, const MInt& rhs) { return lhs /= rhs; }
	    friend constexpr MInt operator^(MInt lhs, ll n) { return power(lhs, n); }
	    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) { long long v; is >> v; a = MInt(v); return is; }
	    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
	    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
	    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
	};
	 
	template<int V, int P> constexpr MInt<P> CInv = MInt<P>(V).inv();
	 
	constexpr int P = 998244353;
	using Z = MInt<P>;
	 
	struct Comb {
	    int n;
	    std::vector<Z> _fac, _invfac, _inv;
	    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
	    Comb(int n) : Comb() { init(n); }
	    void init(int m) {
	        if (m <= n) return;
	        _fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
	        for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
	        _invfac[m] = _fac[m].inv();
	        for (int i = m; i > n; i--) {
	            _invfac[i - 1] = _invfac[i] * i;
	            _inv[i] = _invfac[i] * _fac[i - 1];
	        }
	        n = m;
	    }
	    Z fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
	    Z invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
	    Z inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
	    Z binom(int n, int m) { if (n < m || m < 0) return 0; return fac(n) * invfac(m) * invfac(n - m); }
	} comb;
	 
	using mat = vector<vector<Z> >;
	
	void init(mat &x, int n, int m) {
		x.resize(n);
		for (int i = 0; i < n; i++) x[i].resize(m, Z(0));	
	}
	mat operator * (mat A, mat B) {
		int n = A.size(), k = B.size(), m = B[0].size();
		mat rlt; init(rlt, n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int t = 0; t < k; t++) {
					rlt[i][j] += A[i][t] * B[t][j];	
				}
			}
		}
		return rlt;
	}
	mat power_mat(mat A, long long n) { // n > 0
		if (n == 1) return A;
		mat tp = power_mat(A, n / 2);
		tp = tp * tp;
		if (n & 1) tp = tp * A;
		return tp;	
	}
};
using namespace ModNumber;

void solve() {
	int N, K; cin >> N >> K;

	vector<vector<pair<int,int>>> g(N+1);
	for(int i = 1; i < N; i ++) {
		int x, y, z; cin >> x >> y >> z;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	
	auto can = [&](int M) {
		vector dp(N+1, vector(N+1, inf<int>));
		vector<int> siz(N+1);
		function<void(int u, int p)> dfs = [&](int u, int p) {
			dp[u][0] = 1;
			siz[u] = 1;
			for(auto [v, w] : g[u]) {
				if(v == p) continue;
				dfs(v, u);
				vector<int> ndp(N+1, inf<int>);
				for(int i = 0; i < min(K+1, siz[u]); i ++) {
					if(dp[u][i] == inf<int>) continue;
					for(int j = 0; j < min(K+1, siz[v]); j ++) {
						if(dp[v][j] > M) continue;
						if(dp[u][i] == 0) {
							chkmin(ndp[i+j], 0);
						} else {
							chkmin(ndp[i+j], dp[u][i] + dp[v][j]);
						}
					}
				}
				if(w == 0) {
					for(int i = 0; i < min(K+1, siz[u]); i ++) {
						if(dp[u][i] == inf<int>) continue;
						for(int j = 0; j < min(K+1, siz[v]); j ++) {
							if(dp[v][j] == inf<int>) continue;
							// guard to u
							if(dp[v][j] <= M) {
								chkmin(ndp[i+j+1], 0);
							}
							// guard to v
							chkmin(ndp[i+j+1], dp[u][i]);
						}
					}
				}
				siz[u] += siz[v];
				swap(dp[u], ndp);
			}
		};
		dfs(1, 1);
		return dp[1][K] <= M;
	};
	auto WeakNess = [&]() -> int {
		int lo = 1, hi = N;
		while(lo < hi) {
			int mid = lo + hi >> 1;
			if(can(mid)) hi = mid;
			else lo = mid+1;
		}
		return lo;
	};
	int M = WeakNess();

	auto getValue = [&](Z x) -> Z {
		vector dp(N+1, vector(N+1, Z(0)));
		vector<int> siz(N+1, 0);
		function<void(int,int)> dfs = [&](int u, int p) {
			siz[u] = 1;
			dp[u][1] = 1;
			for(auto [v, w]: g[u]) {
				if(v == p) continue;
				dfs(v, u);
				vector<Z> ndp(N+1, 0);
				// no guard
				for(int i = 0; i <= siz[u]; i ++) {
					for(int j = 0; j <= min(M, siz[v]); j ++) {
						if(i == 0) {
							ndp[0] += dp[u][i] * dp[v][j];
						}
						else {
							ndp[i+j] += dp[u][i] * dp[v][j];
						}
					}
				}
				if(w == 0) {
					// guard to u
					for(int i = 0; i <= siz[u]; i ++) {
						for(int j = 0; j <= min(M, siz[v]); j ++) {
							ndp[0] += dp[u][i] * dp[v][j] * x;
						}
					}
					// guard to v
					for(int i = 0; i <= siz[u]; i ++) {
						for(int j = 0; j <= siz[v]; j ++) {
							ndp[i] += dp[u][i] * dp[v][j] * x;
						}
					}
				}
				swap(dp[u], ndp);
				siz[u] += siz[v];
			}
		};
		dfs(1, 1);
		Z rlt = 0;
		for(int i = 0; i <= M; i ++) {
			rlt += dp[1][i];
		}
//		dbg(dp);
		return rlt;
	};
	auto Counting = [&]() -> Z {
		vector<Z> y(N+1, 0);
		for(int i = 0; i <= N; i ++) {
			y[i] = getValue(i);
		}
//		dbg(y);
		vector<Z> f(N+2, 0);
		f[0] = 1;
		for(int i = 0; i <= N; i ++) {
			for(int j = N+1; j >= 0; j --) {
				f[j] = f[j] * Z(-i);
				if(j) f[j] += f[j-1];
			}
		}
		Z rlt = 0;
		for(int i = 0; i <= N; i ++) {
			if(y[i] == 0) continue;
			Z drlt = y[i];
			Z den = comb.fac(i) * comb.fac(N - i);
			if((N - i) & 1) den = -den;
			drlt /= den;
			vector<Z> g(N+2, 0);
			for(int j = N; j >= 0; j --) {
				g[j] = f[j+1] + g[j+1] * Z(i);
			}
			rlt += drlt * g[K];
		}
		return rlt;
	};
	
	Z ans = Counting();
	cout << M << " " << ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int Tc = 1;
	cin >> Tc;
	while (Tc --) {
		solve();
	}

	return 0;
}