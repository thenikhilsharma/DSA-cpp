/*
n = 4
- - - 1 - - -
- - 1 2 1 - -
- 1 2 3 2 1 -
1 2 3 4 3 2 1
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int row=1; row<=n; row++) {
        for (int spaces=1; spaces<=n-row; spaces++) {
            cout << "  ";
        }
        for (int num=1; num<=row; num++) {
            cout << num << " ";
        }

        for (int reverse = row-1; reverse>=1; reverse--){
            cout << reverse << " ";
        }
        cout << endl;
    }
}