
// top down - memoization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return check(text1, text2, 0, 0, dp);
    }
    int check(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        if (i == text1.length() || j == text2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (text1[i] == text2[j]) return ans = (1 + check(text1, text2, i + 1, j + 1, dp));
        else return ans = max(check(text1, text2, i + 1, j, dp), check(text1, text2, i, j + 1, dp));
        return dp[i][j] = ans;
    }
};

// bottom up - tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return check(text1, text2);
    }
    int check(string &text1, string &text2){
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};