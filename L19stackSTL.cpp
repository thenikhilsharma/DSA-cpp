#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1); // Base for the first valid substring
    int maxLen = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main()
{
    string s = ")()())";
    cout << longestValidParentheses(s);
}