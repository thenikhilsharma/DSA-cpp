// encapsulation is wrapping up of data & member functions in a single unit called class
// data hiding

#include<iostream>
using namespace std;

class Account {
  private: // data hiding
    double balance;
    string password;
  
  public:
    string accountID;
    string username;
};