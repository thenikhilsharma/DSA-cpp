#include <iostream>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;
    char initial_a = a[0];
    char initial_b = b[0];
    a[0] = initial_b;
    b[0] = initial_a;
    cout << a << " " << b << endl;
}