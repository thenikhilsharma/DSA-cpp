// brute force
class Solution {
public:
    string subs(string& s) {
        int n = s.length();
        int ans=0;
        string ansStr = "";

        for (int i = 0; i < n; ++i) {
            for (int len = 1; len <= n - i; ++len) {
                string str = s.substr(i, len);
                if (pali(str) && str.size() > ans) {
                    ansStr = str;
                    ans = str.size();
                }
            }
        }
        return ansStr;
    }

    bool pali(string &str) {
        int low=0, high=str.size()-1;
        while (low<=high) {
            if (str[low] != str[high]) return false;
            low++, high--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        return subs(s);
    }
};

// optimised solution
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};