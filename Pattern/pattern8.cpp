/*
n = 4
1
2 3
3 4 5
4 5 6 7
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    for(int i=1; i<=n; i++) {
        for (int j=i; j<i*2; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}