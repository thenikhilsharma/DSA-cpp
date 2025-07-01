#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define ala(b) begin(b), end(b)
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args>
    decltype(auto) operator()(Args &&...args)
    {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun)
{
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void test()
{
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    pos[0] = 1;
    int bit = log2(n);
    int mx = 1 << bit;
    pos[1] = 1;
    pos[2] = mx;
    // cout << mx << endl;
    vector<int> vis(n + 1);
    for (int j = 4; j <= mx; j *= 2)
    {
        pos[j] = j / 2;
        vis[j/2]=1;
        // cout << j << " " << pos[j] << endl;
    }
    vis[mx]=1;
    // for (int i = 1; i <= n; ++i)
    //     cout << pos[i] << " ";
    cout << endl;
    for (int i = 3; i <= n; ++i)
    {
        
        if (!vis[i])
        {
            vis[i] = 1;
            int curr = i;
            for (int j = i; j <= n; j += i)
            {
                if(pos[j]!=0)
                continue;
                while (curr <= n && vis[curr])
                    curr += i;
                if (curr > n)
                {
                    pos[j] = i;
                    break;
                }
                pos[j] = curr, vis[curr] = 1;
            }
        }
        // cout << i << endl;
        // for (int i = 1; i <= n; ++i)
        //     cout << pos[i] << " ";
        // cout << endl;
    }
    for (int i = 1; i <= n; ++i)
        cout << pos[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        test();
    }
}