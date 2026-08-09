// https://www.codechef.com/problems/TREEGUARD

#include <bits/stdc++.h>
using namespace std;
#define get_bit(x,i) ((x)&(1ll<<(i)))
#define sq(x) (1ll*(x)*(x))
#define msb(x) (__builtin_clz(1)-__builtin_clz(x))
#define el '\n'
#define lef(x) ((x)<<1)
#define rig(x) (lef(x)|1)
using ll = long long int; using ull = unsigned long long int; using ld = long double;
template<class T> using vc = vector<T>; template<class T> using vvc = vector<vc<T>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 2e3+10;

vc<pair<int,int>> g[MAX];
int dp[MAX][MAX],tam[MAX];
int tmp[MAX];
int sp = MAX-1;

void dfs(int u,int ant,int x){
    tam[u] = 1;
    for(auto [v,c] : g[u]) if(v != ant) dfs(v,u,x);
    for(auto [v,c] : g[u]) if(v != ant) tam[u] += tam[v];
    for(int i=0; i<=tam[u]; i++) dp[u][i] = MAX;
    int sum = 0; int tot = 0, qt = 0, bst = MAX;
    // vou usar uma aresta de baixo
    for(auto [v,c] : g[u]) if(v != ant){
        int aux = MAX;
        for(int j=0; j<=min(x,tam[v]); j++) aux = min(aux, dp[v][j]);
        sum += min(c == 0 ? dp[v][sp] : MAX,aux);
        tot += (c == 0), qt += (c == 0 && dp[v][sp] < aux);
        bst = (c == 0 && dp[v][sp] < aux ? min(bst,-dp[v][sp]+aux) : bst);
    }
    dp[u][0] = (tot == 0 ? MAX : (tot == qt ? sum + bst : sum))+1;
    // vou usar uma aresta de cima
    sum = 0;
    for(auto [v,c] : g[u]) if(v != ant){
        int aux = MAX;
        for(int j=0; j<=min(x,tam[v]); j++) aux = min(aux, dp[v][j]);
        aux = min(aux, c == 0 ? dp[v][sp] : MAX);
        sum += aux;
    }
    dp[u][sp] = sum+1;
    // n vou usar aresta
    dp[u][1] = 0, tot = 1;
    for(auto [v,c] : g[u]) if(v != ant){
        for(int j=0; j<=min(x,tot+tam[v]); j++) tmp[j] = MAX;
        for(int j=1; j<=min(x,tot); j++){
            for(int ot=0; ot<=min(x,tam[v]) && j+ot<=x; ot++) tmp[j+ot] = min(tmp[j+ot], dp[u][j] + dp[v][ot]);
            if(c == 0) tmp[j] = min(tmp[j],dp[u][j] + dp[v][sp]);
        }
        for(int j=1; j<=min(x,tot+tam[v]); j++) dp[u][j] = tmp[j];
        tot += tam[v];
    }
    for(int j=0; j<=tam[u]; j++) dp[u][j] = min(dp[u][j],MAX);
    // cout << "U:" << el;
    // cout << u << el;
    // for(int j=0; j<=tam[u]; j++) cout << dp[u][j] << ' ';
    // cout << dp[u][sp] << el;
    // cout << el;
}

void test(){
    int n,k; cin >> n >> k;
    for(int i=1; i<n; i++){
        int a,b,c; cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    int l = 1, r = n,mid,ans=n;
    dfs(1,1,1);
    while(l <= r){
        mid = l + r;
        mid >>= 1;
        dfs(1,1,mid);
        int ok = 0;
        for(int i=0; i<=mid; i++) ok |= (dp[1][i] <= k);
        // cout << "opa " << mid << ' ' << ok << el;
        if(ok) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << el;
    for(int i=1; i<=n; i++) g[i].clear();
}   

int main (){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int ttt_ = 1;
    cin >> ttt_;
    while(ttt_--) test();
    return 0;
}