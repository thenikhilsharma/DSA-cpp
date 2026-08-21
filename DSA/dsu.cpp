struct DSU {
    vector<int> par, rnk, sz;
    DSU(int n) : par(n), rnk(n, 0), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        while (par[x] != x) {
            par[x] = par[par[x]]; // path halving
            x = par[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};