#include<iostream>
using namespace std;

void update1(int m){   // pass by value
    m++;
}

void update2(int &m){  // pass by reference
    m++;
}
/* return by reference #but its dangerous practise
void& fun(int a){
    int num = a;
    int& ans = num;
}*/

int main() {

    int i = 5;
    int &j = i;
    cout << i << endl << j << endl; // point the same memory block but with different name
    cout << &i << endl << &j << endl;

    // pass by value
    int n = 10;
    cout << "Before " << n << endl;
    update1(n);
    cout << "After " << n << endl;

    // pass by reference
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;



    return 0;
}