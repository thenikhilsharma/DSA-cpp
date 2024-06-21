/*
n = 4
- - - *
- - * *
- * * *
* * * *
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int row=1; row<=n; row++) {
    char start = 'A' + row - 1;
        for (int col=n; col>=1; col--) {
            if (col <= row) {
                cout << "* ";
            }
            else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}