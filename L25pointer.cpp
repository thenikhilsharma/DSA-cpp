#include<iostream>

using namespace std;

int main() {

    // declaring a pointer method1
    int num = 5;
    int *ptr = &num;
    cout << num << endl << *ptr << endl;

    //declaring a pointer method2
    int num2 = 6;
    int *ptr2 = 0; //null pointer
    ptr2 = &num2;
    cout << num2 << endl << *ptr2 << endl;

    // copying a pointer
    int *qtr = ptr;
    cout << ptr << " - " << qtr << endl;
    cout << *ptr << " - " << *qtr << endl;
}