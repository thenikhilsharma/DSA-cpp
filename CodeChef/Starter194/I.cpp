#include <iostream>
#include <vector>
using namespace std;

// Generate transitive tournament (diameter N-1)
void transitive_tournament(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) cout << "0";
            else if (i < j) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}

// Generate cyclic tournament (diameter 2)
void cyclic_tournament(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) cout << "0";
            else if ((j - i + N) % N <= N / 2 && (j - i + N) % N != 0) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;
        if (D == N - 1) {
            transitive_tournament(N);
        } else if (D == 2 && N >= 3) {
            cyclic_tournament(N);
        } else if (D == 1 && N == 2) {
            // Only possible for N=2
            cout << "01\n10\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
