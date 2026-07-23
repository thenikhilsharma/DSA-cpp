#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }
  Node *get(char ch) { return links[ch - 'a']; }
  void put(char ch, Node *node) { links[ch - 'a'] = node; }
  void increaseEnd() { cntEndWith++; }
  void increasePrefix() { cntPrefix++; }
  void deleteEnd() { cntEndWith--; }
  void reducePrefix() {  cntPrefix--; }
};

class Trie {
  private:
    Node *root;

  public:
    Trie() { root = new Node(); }

    void insert(string word) {
      Node *node = root;
      for (auto ch : word)
      {
        if (!node->containsKey(ch)) node->put(ch, new Node());
        node = node->get(ch);
        node->increasePrefix();
      }
      node->increaseEnd();
    }

    int countWordsEqualTo(string word)
    {
      Node *node = root;
      for (auto ch : word)
      {
        if (node->containsKey(ch)) node = node->get(ch);
        else return 0;
      }
      return node->cntEndWith;
    }

    int countWordsStartingWith(string word)
    {
      Node *node = root;
      for (auto ch : word)
      {
        if (node->containsKey(ch)) node = node->get(ch);
        else return 0;
      }
      return node->cntPrefix;
    }

    void erase(string word)
    {
      Node *node = root;
      for (auto ch : word)
      {
        if (node->containsKey(ch))
        {
          node = node->get(ch);
          node->reducePrefix();
        }
        else return;
      }
      node->deleteEnd();
    }
};

int main()
{
  Trie trie;
  trie.insert("apple");
  trie.insert("apple");
  cout << "Inserting strings 'apple' twice into Trie" << endl;
  cout << "Count Words Equal to 'apple': ";
  cout << trie.countWordsEqualTo("apple") << endl;
  cout << "Count Words Starting With 'app': ";
  cout << trie.countWordsStartingWith("app") << endl;
  cout << "Erasing word 'apple' from trie" << endl;
  trie.erase("apple");
  cout << "Count Words Equal to 'apple': ";
  cout << trie.countWordsEqualTo("apple") << endl;
  cout << "Count Words Starting With 'app': ";
  cout << trie.countWordsStartingWith("app") << endl;
  cout << "Erasing word 'apple' from trie" << endl;
  trie.erase("apple");
  cout << "Count Words Starting With 'app': ";
  cout << trie.countWordsStartingWith("app") << endl;
  return 0;
}