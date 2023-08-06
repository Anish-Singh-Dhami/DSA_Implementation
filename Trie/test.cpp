#include <iostream>
#include "TrieImplementation.hpp"
int main(){

    Trie *root = new Trie();
    int t; cin >> t;
    while(t--) {
        int a;
        cin >> a;
        if(a == 1) { // insert:
            string s; cin >> s;
            root->insert(s);
        } else if(a == 2) {
            string s; cin >> s;
            cout << boolalpha << root->isPresent(s) << "\n";
        } else {
            string s; cin >> s;
            if(root->isPresent(s)) {
                root->remove(s);
            } else {
                cout << "Not Present\n";
            }
        }
    }
    return 0;
}