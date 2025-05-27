#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v;
  vector<int> a(5, -1); // array(size, initialize) ex: a = {-1 -1 -1 -1 -1}
  vector<int> copyarr(a);

  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  cout << "Size alloted to vector: " << v.capacity() << endl;
  cout << "Occupied space by vector: " << v.size() << endl;
  cout << "Element at 2nd index is: " << v.at(2) << endl;
  cout << v.front() << " " << v.back() << endl;

  v.pop_back();

  for (auto i:v){
    cout << i << " ";
  }
  cout << endl;

  // v.begin(); v.end();
  // v.clear();
}