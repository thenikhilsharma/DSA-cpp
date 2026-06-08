#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i, a, b) for (int i = a; i < b; i++)

struct Snack {
    ll tastiness;
    ll sugar;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Snack> snacks(N);
        loop(i, 0, N) cin >> snacks[i].tastiness;
        loop(i, 0, N) cin >> snacks[i].sugar;


        sort(snacks.begin(), snacks.end(), [](const Snack& a, const Snack& b) {
            return a.sugar < b.sugar;
        });

        ll max_satisfaction = 0;

        ll current_sum_A = 0;

        loop(i, 0, N) {
            if (snacks[i].tastiness > 0) current_sum_A += snacks[i].tastiness;

            ll current_L = snacks[i].sugar;
            ll current_satisfaction = current_sum_A - current_L;

            if (current_satisfaction > max_satisfaction) max_satisfaction = current_satisfaction;
        }
        
        cout << max_satisfaction << endl;
    }

    return 0;
}