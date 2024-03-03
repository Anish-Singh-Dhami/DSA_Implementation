#include <iostream>
#include <memory>
#include "TrieImplementation.hpp"
int main(){

    shared_ptr<Trie> ct = make_shared<Trie> ();
    int t; cin >> t;
    while(t--) {
        int op; cin >> op;
        string s; cin >> s;
        if(op == 1) { // insert:
            ct->insert(s);
        } else if(op == 2) {
            cout << boolalpha << ct->search(s) << "\n";
        } else {
            ct->erase(s);
        }
    }
    return 0;
}