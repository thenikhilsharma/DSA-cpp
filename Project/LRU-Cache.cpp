#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int value;
  Node* next;
  Node* prev;
  
  Node(int key, int value) : key(key), value(value), next(NULL), prev(NULL) {}
};

class LRUCache {
  public:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
      this->capacity = capacity;
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->prev = head;
    }

    ~LRUCache() {
      Node* cur = head;
      while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
      }
    }

    void remove(Node* node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    void insert(Node* node) {
      node->next = head->next;
      node->prev = head;
      head->next->prev = node;
      head->next = node;
    }

    int get(int key) {
      auto it = cache.find(key);
      if (it == cache.end()) return -1;
      Node* node = it->second;
      remove(node);
      insert(node);
      return node->value;
    }

    void put(int key, int value) {
      auto it = cache.find(key);
      if (it != cache.end()) {
        Node* node = it->second;
        node->value = value;   // just update value, don't delete/recreate
        remove(node);
        insert(node);
        return;
      }

      if ((int)cache.size() == capacity) {
        Node* lruNode = tail->prev;
        remove(lruNode);
        cache.erase(lruNode->key);   // now correct
        delete lruNode;
      }

      Node* newNode = new Node(key, value);
      insert(newNode);
      cache[key] = newNode;
    }
};