// special method invoked automatically at time of object creation. Used for initialisation

// same name as of class
// constructor doesn't have any return type
// only called once(automatically) at the time of object creation
// memory allocation happend when the constructor is called

#include<iostream>
using namespace std;

class Teacher {
  public:
    Teacher() {
      cout << "This is a contructor\n";
      dept = "CSE";
    }

    string name;
    string dept;
};

int main() {
  Teacher t1;
  t1.name = "NIKHIL";
  cout << t1.dept << endl;
}