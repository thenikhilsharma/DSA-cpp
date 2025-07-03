#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        // solve
        int no_of_1s= 0, between = 0;
        for (int i = 0; i < n; i++) no_of_1s += (s[i] == '1') ? 1 : 0;
        for(int i=n-k+1 ; i<k+1;++i) between += (s[i] == '1') ? 1 : 0;
        if (( k > n/2 && no_of_1s > k && between < no_of_1s ) || ( k >= no_of_1s )) cout << "Alice\n";
        else cout << "Bob\n";

    }

    return 0;
}