#include <iostream>
using namespace std;

void update(int **p) {

    //p = p + 1;

    //*p = *p + 1;

    //**p = **p + 1;
}

int main() {
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << ptr << endl << ptr2 << endl;
    cout << i << endl << *ptr << endl << **ptr2 << endl;
}