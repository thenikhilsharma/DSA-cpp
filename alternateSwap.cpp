#include<iostream>
using namespace std;

void swapAlternate (int arr[]) {
    int temp;

    for (int j=0; j<6; j = j+2){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
    }
}

int main() {

    int arr[6] = {1, 2, 3, 4, 5, 6};

    swapAlternate(arr);

    for (int k=0; k<6; k++){
        cout << arr[k];
    }
}