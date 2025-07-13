#include <bits/stdc++.h>
using namespace std;

class Teacher {
  public: // access modifiers (private, public, protected)
    // properties or attributes
    string name;
    string dept;
    string subject;
    double salary;

    // method or meber functions
    void changeDept(string newDept) {
      dept = newDept;
    }
};

int main() {
  Teacher t1;
  t1.name = "NIKHIL";
  t1.dept = "MECH";
  t1.subject = "C++";
  t1.salary = 250000;
  cout << t1.name << endl;

  return 0;
}