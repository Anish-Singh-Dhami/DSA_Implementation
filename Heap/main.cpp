#include <bits/stdc++.h>
#include "Heap.hpp"

using namespace std;

int main(){

    int t; cin >> t;
    Heap *hp = new Heap();

    while(t--) {
        int q; cin >> q;
        if(q == 1) {
            int x; cin >> x;
            hp->insert(x);
        } else if(q == 2) {
            if(hp->n == 0) {
                cout << "Not Enough Element" << endl;
            } else {
                cout << "Min Element : " << hp->remove_min() << endl;
            }
        } else {
            if(hp->n == 0) {
                cout << "Not Enough Element" << endl;
            } else {
                cout << "Top Element : " << hp->top() << endl;
            }
        }
    }

    return 0;
}