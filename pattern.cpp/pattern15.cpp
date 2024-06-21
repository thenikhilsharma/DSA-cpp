/*
n = 4
A
B B
C C C
D D D D
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int row=1; row<=n; row++) {
    char start = 'A' + row - 1;
        for (int col=1; col<=row; col++) {
            cout << start << " ";
        }
        cout << endl;
    }
}