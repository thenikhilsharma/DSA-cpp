#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long S = accumulate(a.begin(), a.end(), 0LL);

    unordered_map<long long,int> cnt;
    cnt.reserve(n * 2);
    for (auto x : a) cnt[x]++;

    vector<int> nice;
    for (int j = 0; j < n; j++) {
        long long target = S - a[j];       // sum of the remaining n-1 elements
        if (target % 2 != 0) continue;     // can't split evenly
        long long half = target / 2;

        int need = (half == a[j]) ? 2 : 1; // if a[j] itself equals half, need another copy
        auto it = cnt.find(half);
        if (it != cnt.end() && it->second >= need) {
            nice.push_back(j + 1);         // 1-indexed
        }
    }

    cout << nice.size() << "\n";
    for (int idx : nice) cout << idx << " ";
    cout << "\n";

    return 0;
}