/*
n = 5
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1

*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for (int row=n; row>=1; row--) {
        for (int num=1; num<=row; num++) {
            cout << num << " ";
        }

        if (row < 5) {
            int check = n-row;
            for (int star=1; star<=check*2; star++) {
                cout << "* ";
            }
        }

        for (int reverse = row; reverse>=1; reverse--){
            cout << reverse << " ";
        }
        cout << endl;
    }
}