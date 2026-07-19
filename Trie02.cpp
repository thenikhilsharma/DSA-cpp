// insert
// erase
// countWordsEqualTo
// countWordsStartingWith

#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* children[26] = {nullptr};
  int cnt = 0;

  bool containsKey(char ch) { return children[ch - 'a'] != NULL; }
  void put(char ch, Node* node) { children[ch - 'a'] = node; }
  Node* get(char ch) { return children[ch - 'a']; }
  int setEnd() { return ++cnt; }
  bool isEnd() { return cnt > 0; }
  int countWordsFromNode(Node* node) {
    int count = node -> cnt;
    for (int i = 0; i < 26; i++) {
      if (node->children[i] != nullptr) count += countWordsFromNode(node->children[i]);
    }
    return count;
  }
};

class Trie {
  private:
    Node* root;

  public:
    Trie() { root = new Node(); }

    void insert(string word) {
      Node* node = root;
      for (char ch : word) {
        if (!node -> containsKey(ch)) {
          node -> put(ch, new Node());
        }
        node = node -> get(ch);
      }
      node -> setEnd();
    }

    bool search(string word) {
      Node* node = root;
      for (char ch : word) {
        if (!node -> containsKey(ch)) return false;
        node = node -> get(ch);
      }
      return node -> isEnd();
    }

    bool startsWith(string prefix) {
      Node* node = root;
      for (char ch : prefix) {
        if (!node -> containsKey(ch)) return false;
        node = node -> get(ch);
      }
      return true;
    }

    void erase(string word) {
      Node* node = root;
      for (char ch : word) {
        if (!node -> containsKey(ch)) return;
        node = node -> get(ch);
      }
      if (node -> isEnd()) node -> cnt--;
    }

    int countWordsEqualTo(string word) {
      Node* node = root;
      for (char ch : word) {
        if (!node -> containsKey(ch)) return 0;
        node = node -> get(ch);
      }
      return node -> cnt;
    }

    int countWordsStartingWith(string prefix) {
      Node* node = root;
      for (char ch : prefix) {
        if (!node -> containsKey(ch)) return 0;
        node = node -> get(ch);
      }
      return node->countWordsFromNode(node);
    }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Trie trie;
    int n;
    cin >> n;
    while (n--) {
      string op, word;
      cin >> op >> word;
      if (op == "insert") {
        trie.insert(word);
      } else if (op == "erase") {
        trie.erase(word);
      } else if (op == "countWordsEqualTo") {
        cout << trie.countWordsEqualTo(word) << endl;
      } else if (op == "countWordsStartingWith") {
        cout << trie.countWordsStartingWith(word) << endl;
      }
    }
  }
}