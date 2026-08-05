// https://www.codechef.com/problems/MINREDSR
// prefix Maximas
// red can only move right
// index zero can only have 1 or a blue element
// Two adjacent prefixMaximums only allowed iff they -> next one is == prev +1

#include<bits/stdc++.h>
using namespace std;

void solve(){
  
  int n ; cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  int ans = n;
  int prefixMax = 0;
  int prevPrefixMax = -1; // index
  
  for(int i=0;i<n;i++){
    if(p[i] < prefixMax) continue;
    prefixMax = p[i];
    bool keepRed = false;
    if(i==0){if(p[i] == 1) keepRed = true;}
    else if(prevPrefixMax == -1) keepRed = true;
    else if(i > prevPrefixMax + 1) keepRed = true;
    else if(p[i] == p[prevPrefixMax]+1) keepRed = true;
    
    if(keepRed){
      ans--;
      prevPrefixMax = i;
    }
    
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin>>t;
  while(t--){
    solve();
  }
}