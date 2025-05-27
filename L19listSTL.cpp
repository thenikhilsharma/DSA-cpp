#include<iostream>
#include<list>
using namespace std;

void print(list<int> &d){
  for(auto i:d){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main() {
  list<int> l;
  l.push_back(2);
  l.push_front(3);

  print(l);
  l.erase(l.begin()); // delete that particular index
  print(l);
}