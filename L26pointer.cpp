#include <iostream>
using namespace std;

int main() {

    int arr[10] = {2, 5, 6, 10};

    cout << "address of 1st index " << arr << endl;
    cout << "first element is " << arr[0] << endl;
    cout << "address of 1st index " << &arr[0] << endl;

    cout << *arr << endl;   // access the element on the first index
    cout << *arr + 1 << endl; // access the element on the first index and add 1
    cout << *(arr + 1) << endl; // access the element on the second index
    // arr[i] = *(arr + i)
    // i[arr] = *(i + arr)
}