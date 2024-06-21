#include <iostream>
using namespace std;


class solution {
public:

    int increment(int n) {
        n++;
        return n;
    }

    int decrement(int n) {
        n--;
        return n;
    }
};

int main() {

    int a;
    char name[15];
    cout << "Input a string: ";
    cin >> name;
    cout << "Your string is: " << name << endl;
    cout << "Enter any no: ";
    cin >> a;
    solution obj1;
    int func = obj1.increment(a);
    cout << "value of function is: " <<func << endl;
    cout << "value of a is: " << a << endl;
    int arr1[a];
    int arr2[5];
    for (int i=0; i<a; i++) {
        cin >> arr1[i];
    }
    for (int i=0; i<a; i++) {
        cout << "The " << i << " element is: " << arr1[i] << endl;
        cout << "The " << i << " element is: " << arr2[i] << endl;
    }

    return 0;
}