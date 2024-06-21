/*
n = 4
A B C D
B C D E
C D E F
D E F G
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int row=1; row<=n; row++) {
    char start = 'A' + row - 1;
        for (int col=1; col<=n; col++) {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}