#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    // Initialize Fenwick tree for 'size' elements (1-indexed internally)
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    // Build tree from an existing array (0-indexed input)
    FenwickTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) update(i + 1, arr[i]);   // convert to 1-indexed
    }

    // Add 'delta' to element at position i (1-indexed)
    void update(int i, int delta) {
        for (; i <= n; i += i & (-i)) tree[i] += delta;
    }

    // Prefix sum of elements [1..i]
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) sum += tree[i];
        return sum;
    }

    // Range sum [l..r] (1-indexed, inclusive)
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    // Set element at position i (1-indexed) to 'value'
    void pointUpdate(int i, int value, vector<int>& original) {
        int delta = value - original[i - 1];
        original[i - 1] = value;
        update(i, delta);
    }
};

int main() {
    // Original array (0-indexed for readability)
    vector<int> arr = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

    // Build Fenwick tree
    FenwickTree fenwick(arr);

    // 1. Prefix sum queries
    cout << "Prefix sum [1..5]: " << fenwick.query(5) << endl; // 3+2-1+6+5 = 15
    cout << "Prefix sum [1..10]: " << fenwick.query(10) << endl;

    // 2. Range sum query
    cout << "Range sum [3..7]: " << fenwick.rangeQuery(3, 7) << endl; // -1+6+5+4-3 = 11

    // 3. Point update: add 10 to index 4 (1-indexed) -> arr[3] in 0-indexed
    cout << "\nUpdating index 4 (1-indexed) by adding 10...\n";
    fenwick.update(4, 10);
    arr[3] += 10; // keep our reference array in sync for display
    cout << "Updated array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "New prefix sum [1..5]: " << fenwick.query(5) << endl; // should increase by 10
    cout << "New range sum [3..7]: " << fenwick.rangeQuery(3, 7) << endl;

    // 4. Point set: set index 7 (1-indexed) to value 100
    cout << "\nSetting index 7 (1-indexed) to 100...\n";
    fenwick.pointUpdate(7, 100, arr);
    cout << "Updated array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    cout << "New prefix sum [1..10]: " << fenwick.query(10) << endl;

    return 0;
}