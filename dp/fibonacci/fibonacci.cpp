#include<iostream>
using namespace std;

int solution(int n){
    if (n == 1 || n == 0){
        return n;
    }
    return solution(n-1) + solution(n-2);
}

int main() {
    int t;
    cin >> t;
    cout << solution(t);

    return 0;
}