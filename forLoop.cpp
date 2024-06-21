#include<iostream>
using namespace std;

int main() {

    int n, a;
    cin>>n;

    for (int i=0; i<=n; i++) {
        a = a+i;
    }

    cout << "Sum of all num till n is: " << a;
}