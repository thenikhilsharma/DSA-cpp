class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sol = 0;
        unordered_set<string> words;
        for (const string& s : wordList) words.insert(s);

        if (words.find(endWord) == words.end()) return sol;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [original, size] = q.front();
            if (original == endWord) return size;
            q.pop();
            int len = original.size();
            for (int i = 0; i < len; i++) {
                string curr = original;
                for (char j = 'a'; j <= 'z'; j++) {
                    curr[i] = j;
                    if(words.find(curr)!=words.end()){
                        q.push({curr,size+1 });
                        words.erase(curr);
                    }
                }
            }
        }
        return sol;
    }
};