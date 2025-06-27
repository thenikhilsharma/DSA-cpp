#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string infixToPostfix (string s) {
  int i = 0;
  string ans = "";
  stack<char> st;

  unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
  
  while (i < s.size()) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
      ans += s[i];
    }
    else if (s[i] == '(') st.push(s[i]);
    else if (s[i] == ')') {
      while(!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    }
    else {
      while (!st.empty() && priority[s[i]] <= priority[st.top()]) {
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  return ans;
}

int main() {
  string s = "a+b*(c^d-e)";
  cout << infixToPostfix(s);
}