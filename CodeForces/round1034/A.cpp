/* A. Blackboard Game
Initially, the integers from 0 to n−1 are written on a blackboard.

In one round,
Alice chooses an integer a on the blackboard and erases it; then Bob chooses an integer b on the blackboard such that a+b≡3(mod4) and erases it.
Rounds take place in succession until a player is unable to make a move — the first player who is unable to make a move loses. Determine who wins with optimal play.

We define that x≡y(modm) whenever x−y is an integer multiple of m
*/

#include <iostream>
#include <string>
using namespace std;

string winner(int n) {
  if (n % 4 == 0) return "Bob";
  else return "Alice";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << winner(n) << endl;
  }
  return 0;
}