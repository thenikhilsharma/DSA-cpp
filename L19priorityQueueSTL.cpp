#include<iostream>
#include<queue>

using namespace std;

int main(){

  priority_queue<int> maxi; // max heap
  priority_queue<int, vector<int>, greater<int>> mini; // min heap

  maxi.push(2);
  maxi.push(4);
  maxi.push(1);
  maxi.push(6);
  maxi.top(); maxi.pop(); // greatest element will pop or top first
  // opposite for min heap
}