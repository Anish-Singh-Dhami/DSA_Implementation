#include <vector>
#include <memory>
using namespace std;

#ifndef TRIE_HPP
#define TRIE_HPP

class Node {
public:
  vector<shared_ptr<Node>> child;
  int end;
  Node() {
    child.assign(26, NULL);
    end = 0;
  }
};
class Trie {
public:
  shared_ptr<Node> root;
  Trie() {
    root = make_shared<Node>();
  }
  void insert(string &s) {
    shared_ptr<Node>node = root;
    for(int i = 0; i < (int)s.size(); i++) {
      if(node->child[s[i]-'a'] == NULL) {
        node->child[s[i]-'a'] = make_shared<Node>();
      }
      node = node->child[s[i]-'a'];
    }
    node->end++;
  }
  bool search(string &s) {
    shared_ptr<Node>node = root;
    for(int i = 0; i < (int)s.size(); i++) {
      if(node->child[s[i]-'a'] == NULL) return false;
      node = node->child[s[i]-'a'];
    }
    return node->end;
  }

  bool isEmpty(shared_ptr<Node> node) {
    return node->child.empty() and node->end == 0;
  }
  bool erase(string &s, int idx, shared_ptr<Node> node) {
    if(idx == (int)s.size()) {
      node->end--;
      if(isEmpty(node)) {
        node.reset();
        return true;
      }
      return false;
    }

    bool remove = erase(s, idx+1, node->child[s[idx]-'a']);
    if(remove) {
      if(isEmpty(node)) {
        node.reset();
        return true;
      }
      return false;
    } 
    return false;
  }
  void erase(string &s) {
    if(!search(s)) return;
    erase(s, 0, root);
  }
};
#endif