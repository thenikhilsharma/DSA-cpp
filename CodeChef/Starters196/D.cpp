#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long minimizeSum(int N, int K, vector<int> &A) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : A) {
        minHeap.push(num);
    }

    long long sum = 0;
    for (int num : A) {
        sum += num;
    }

    for (int i = 0; i < K; ++i) {
        int smallest = minHeap.top();
        minHeap.pop();
        int secondSmallest = minHeap.top();
        minHeap.pop();

        int newNum = (smallest + secondSmallest + 1) / 2; // This handles both even and odd sums correctly

        sum += newNum;
        minHeap.push(newNum);
        minHeap.push(smallest); // Push back the smallest to maintain the heap properties
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << minimizeSum(N, K, A) << endl;
    }
    return 0;
}