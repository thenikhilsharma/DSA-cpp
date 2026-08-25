#include <iostream>
using namespace std;

int main() {
    
    int n;

    cout << "Enter a number: ";
    cin >> n;

    for (int i=1; i<=n; i++) {
        int j = n-i+1;
        while (j >= 1) {
            cout << i << " ";
            j--;
        }
        cout << endl;
    }
}