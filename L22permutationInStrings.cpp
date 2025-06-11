// LeetCode q567

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        int len = s1.length();
        for (int i = 0; i < len; i++) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        for (int i = len; i < s2.length(); i++) {
            if (compare_unordered_maps(mpp1, mpp2)) {
                return true;
            }
            char leftChar = s2[i - len];
            mpp2[leftChar]--;
            if (mpp2[leftChar] == 0) {
                mpp2.erase(leftChar);
            }
            mpp2[s2[i]]++;
        }
        return compare_unordered_maps(mpp1, mpp2);
    }

    bool compare_unordered_maps(const unordered_map<char, int>& map1,
                               const unordered_map<char, int>& map2) {
        if (map1.size() != map2.size()) {
            return false;
        }

        for (const auto& pair : map1) {
            auto it = map2.find(pair.first);
            if (it == map2.end() || it->second != pair.second) {
                return false;
            }
        }

        return true;
    }
};