#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define loop(i, a, b) for (int i = a; i < b; i++)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0); // tracks how many people trust each person
        vector<bool> trustsSomeone(n + 1, false); // tracks who trusts someone
        
        for (auto& relation : trust) {
            trustsSomeone[relation[0]] = true;
            trustCount[relation[1]]++;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (!trustsSomeone[i] && trustCount[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};