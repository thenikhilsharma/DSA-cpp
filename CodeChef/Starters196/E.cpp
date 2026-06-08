#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i < b; i++)

void swaparr(vector<int>& A, vector<int>& B) {
    for (int i = 0; i < A.size(); i++) {
        swap(A[i], B[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> initial_A(N), initial_B(N);
        loop(i, 0, N) cin >> initial_A[i];
        loop(i, 0, N) cin >> initial_B[i];

        int q;
        cin >> q;
        while (q--) {
            vector<int> A_current = initial_A;
            vector<int> B_current = initial_B;

            int type, p, x;
            cin >> type >> p >> x;

            if (type == 1) {
                A_current[p - 1] = x;
            } else {
                B_current[p - 1] = x;
            }

            int score = 0;
            for (int i = 0; i < N; ++i) {
                if (A_current[i] + K < B_current[i]) {
                    swaparr(A_current, B_current);
                }
                score += A_current[i];
            }

            cout << score << "\n";
        }
    }
    return 0;
}