#include<iostream>
using namespace std;

int main() {
    int a, b;

    cout<< "Input a variables: ";
    cin>> a >> b;
    cout<< "Variables are: " <<a <<b <<endl;

    if (a>b){
        cout<< "A is greater" << endl;
    }
    else if (b>a){
        cout<< "B is greater" << endl;
    }
    else{
        cout<< "Both are same" << endl;
    }
}