/*
n = 3

1 2 3
4 5 6
7 8 9
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int i=1; i<=n*n; i++) {
        if (i % n == 0) {
            cout << i << endl;
        }
        else {
            cout << i << " ";
        }
    }
}