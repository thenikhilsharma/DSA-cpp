/*
n = 4
A B C D
E F G H
I J K L
M N O P
*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter a num: ";
    cin >> n;

    char start = 'A';
    int row = 1;
    while (row <= n) {
        int col = 1;
        while (col <= n) {
            cout << start << " ";
            start++;
            col++;
        }
        cout << endl;
        row++;
    }
}