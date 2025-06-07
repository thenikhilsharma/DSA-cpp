#include<iostream>
#include<deque>
using namespace std;

void print(deque<int> &d){
  for(auto i:d){
    cout<<i<<" ";
  }
  cout<<endl;
}

int main(){

  deque<int> d;
  deque<int> d2(5, -1);
  print(d2);

  d.push_back(1);
  d.push_back(3);
  d.push_front(2);
  d.push_front(4);
  print(d);
  cout << d.front() << endl;
  d.pop_back();
  print(d);
  d.erase(d.begin(), d.begin()+1); // erase(start index, end index)
}