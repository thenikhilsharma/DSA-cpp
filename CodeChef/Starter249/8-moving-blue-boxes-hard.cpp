// https://www.codechef.com/problems/MINREDSR2

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define endl '\n'
#define sz(a) (int)a.size()
#define setbits(x) __builtin_popcountll(x)
#define ff first
#define ss second
#define conts continue
#define ceil2(x,y) ((x+y-1)/(y))
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rev(i,s,e) for(int i = s; i >= e; --i)
#define trav(i,a) for(auto &i : a)

template<typename T>
void amin(T &a, T b) {
    a = min(a,b);
}

template<typename T>
void amax(T &a, T b) {
    a = max(a,b);
}

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

/*



*/

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int inf1 = int(1e9) + 5;
const ll inf2 = ll(1e18) + 5;

template<typename T>
struct segtree {
    // https://codeforces.com/blog/entry/18051

    /*=======================================================*/

    struct data {
        ll a;
    };

    data neutral = {inf2};

    data merge(data &left, data &right) {
        data curr;
        curr.a = min(left.a,right.a);
        return curr;
    }

    void create(int i, T v) {

    }

    void modify(int i, T v) {
        tr[i].a = v;
    }

    /*=======================================================*/

    int n;
    vector<data> tr;

    segtree() {

    }

    segtree(int siz) {
        init(siz);
    }

    void init(int siz) {
        n = siz;
        tr.assign(2 * n, neutral);
    }

    void build(vector<T> &a, int siz) {
        rep(i, siz) create(i + n, a[i]);
        rev(i, n - 1, 1) tr[i] = merge(tr[i << 1], tr[i << 1 | 1]);
    }

    void pupd(int i, T v) {
        modify(i + n, v);
        for (i = (i + n) >> 1; i; i >>= 1) tr[i] = merge(tr[i << 1], tr[i << 1 | 1]);
    }

    data query(int l, int r) {
        data resl = neutral, resr = neutral;

        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) resl = merge(resl, tr[l++]);
            if (!(r & 1)) resr = merge(tr[r--], resr);
        }

        return merge(resl, resr);
    }
};

void solve(int test_case){
    ll n; cin >> n;
    vector<ll> a(n+5);
    rep1(i,n) cin >> a[i];

    // find range on left for which max
    vector<ll> lx_max_range(n+5,1);
    
    {
        stack<ll> stk;
        rev(i,n,1){
            while(!stk.empty() and a[i] > a[stk.top()]){
                lx_max_range[stk.top()] = i+1;
                stk.pop();
            }

            stk.push(i);
        }
    }

    // find the range on the right for which val is min
    vector<ll> rx_min_range(n+5,n);

    {
        stack<ll> stk;
        rep1(i,n){
            while(!stk.empty() and a[i] < a[stk.top()]){
                rx_min_range[stk.top()] = i-1;
                stk.pop();
            }

            stk.push(i);
        }
    }

    // for every adjacent pair where a[i] < a[i+1], find the first position j >= i+2 whose val is in between (a[i],a[i+1])
    // reverse sweepline on indices, maintain min segtree
    segtree<ll> st(n+5);
    vector<ll> first_between(n+5,n+1);
    
    rev(i,n,1){
        if(i < n and a[i] < a[i+1]){
            ll val = st.query(a[i]+1,a[i+1]-1).a;
            first_between[i] = min(val,n+1);
        }

        st.pupd(a[i],i);
    }

    // goal: find sum of untouched over all ranges
    // fix a sub-block [i..j] and add contrib
    ll tot_sum = 0;

    deque<array<ll,3>> dq; // (i,val,suffix_sum)
    dq.pb({n+1,inf2,0});

    auto get_sum = [&](ll i, ll s){
        // find first pos with val >= s
        ll lo = 0, hi = sz(dq)-1;
        ll first_pos = -1;

        while(lo <= hi){
            ll mid = (lo+hi)>>1;
            if(dq[mid][1] >= s){
                first_pos = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        ll mxr = dq[first_pos][0];
        ll sub_sum = dq[0][2]-dq[first_pos][2];
        ll add_sum = 0;
        ll len = mxr-i;
        if(len&1){
            if(mxr&1) add_sum = -s;
            else add_sum = s;
        }

        // spl case: i = j
        ll c = 1;
        if(i&1) c = -1;
        ll singular = c*max(s-i,0ll);;
        
        ll res = add_sum-sub_sum+singular;
        return res;
    };
    
    rev(i,n,1){
        // insert i into prefix max dq
        ll vali = first_between[i];
        while(vali > dq[0][1]){
            dq.pop_front();
        }

        {
            auto [j,valj,suffj] = dq[0];
            ll len = j-i;
            
            if(len&1){
                // if even, suffj will remain same (-1 and +1 will cancel out)
                // otherwise, suffj will change
                if(j&1){
                    // addl guy is -
                    suffj -= vali;
                }
                else{
                    // addl guy is +
                    suffj += vali;
                }
            }

            dq.push_front({i,vali,suffj});
        }

        ll lx = lx_max_range[i]; // [lx..i] --> i is max val, so any left endpoint starting here is fine
        ll rx = rx_min_range[i]; // [i..rx] --> i is min val, so any right endpoint inside this range is fine

        ll l_ways = i-lx; // lx <= left < i
        ll c = 1;
        if(i&1) c = -1;
        
        ll ways1 = l_ways*get_sum(i,n+1);
        ll ways2 = get_sum(i,rx+1);
        ll ways = ways1+ways2;
        tot_sum += ways*c;
    }

    // find sum of all lengths, to find sum of touched over all subarrays
    ll tot_len = 0;
    rep1(len,n){
        tot_len += len*(n-len+1);
    }

    ll ans = tot_len-tot_sum;
    cout << ans << endl;
}

int main()
{
    fastio;

    int t = 1;
    cin >> t;

    rep1(i, t) {
        solve(i);
    }

    cerr << "RUN SUCCESSFUL" << endl;

    return 0;
}