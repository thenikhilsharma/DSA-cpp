#include<iostream>
using namespace std;

int main() {

    int a = 123;        //4 byte
    char ch = 'c';      //1 byte
    bool b = true;      //1 Bit
    float f = 1.4;      //8 byte
    double d = 1.55;    //8 byte

    cout<< a << endl;
    cout<< b << endl;

    int size = sizeof(a);
    cout<< "Size of a is :"<< size << endl;
}