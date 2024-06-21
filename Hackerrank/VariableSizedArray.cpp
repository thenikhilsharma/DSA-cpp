#include <iostream>
using namespace std;

int main() {

    int n, q;   // no of array and no of queries
    cin >> n >> q;  // taking input
    int parent_array[n];

    for (int j=0; j<n; j++) {
        int size;
        cin >> size;
        int array[size];
        parent_array[j] = array;
    }

    int array[size];
    for (int i=0; i<size; i++) {
        cin >> array[i];
    }
}