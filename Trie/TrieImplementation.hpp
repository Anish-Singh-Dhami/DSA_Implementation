#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *child[26];
    int wordEnd;
    TrieNode()
    {
        wordEnd = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie
{
private:
    TrieNode *root;

    void insert(TrieNode *root, string s, int idx)
    {
        if (idx == s.size())
        {
            root->wordEnd++;
            return;
        }
        TrieNode *newNode;
        if (root->child[s[idx] - 'a'] == NULL)
        {
            newNode = new TrieNode();
            newNode->data = s[idx];
            root->child[s[idx] - 'a'] = newNode;
        }
        else
        {
            newNode = root->child[s[idx] - 'a'];
        }
        insert(newNode, s, idx + 1);
    }
    bool isPresent(TrieNode *root, string s, int idx)
    {
        if (s.size() == idx)
            return root->wordEnd > 0;

        if (root->child[s[idx] - 'a'] != NULL)
            return isPresent(root->child[s[idx] - 'a'], s, idx + 1);
        return false;
    }
    bool isPrefix(TrieNode *root, string s, int idx)
    {
        if (s.size() == idx)
            return true;
        if (root->child[s[idx] - 'a'] != NULL)
            return isPrefix(root->child[s[idx] - 'a'], s, idx + 1);
        return false;
    }
    void remove(TrieNode *root, string s, int idx)
    {
        if (s.size() == idx)
        {
            root->wordEnd--;
            return;
        }
        remove(root->child[s[idx] - 'a'], s, idx + 1);
    }

public:
    Trie()
    {
        root = new TrieNode();
        root->data = '$';
    }

    void insert(string &s)
    {
        insert(root, s, 0);
    }

    bool isPrefix(string &s)
    {
        return isPrefix(root, s, 0);
    }

    bool isPresent(string &s)
    {
        return isPresent(root, s, 0);
    }

    void remove(string &s)
    {
        remove(root, s, 0);
    }
};
