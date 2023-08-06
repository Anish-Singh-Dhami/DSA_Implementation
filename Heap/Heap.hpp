// By Default Min Heap:
#include <vector>
#include <iostream>

using namespace std;
class Heap { 
    vector<int> heap;

    public :
    int n;
    Heap() {
        n = 0;
    }

    void insert(int x) {
        // will insert at last position:
        heap.push_back(x);
        n++;
        // can break the heap property (i.e. parent <= children, for min_heap):
        int i = n-1;
        while(i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i =  (i - 1) / 2;
        }
    }

    int remove_min() {
        n--;
        swap(heap[0], heap[n]);
        // can break the heap property:

        int i = 0; // breaking index (which might have the break the heap property).
        // will place it in it's right position:
        while(2 * i + 1 < n) { // atleast 1 child:
            int j = 2 * i + 1;
            if((2 * i + 2 < n) && (heap[2 * i + 2] < heap[j])) { // choose the min among the child
                j = 2 * i + 2;
            }
            if(heap[i] > heap[j]) {
                swap(heap[i] , heap[j]);
                i = j;
            } else {
                break;
            }
        }
        int lst = heap[n];
        heap.pop_back();
        return lst;
    }
    int top() {
        if(heap.empty()) {
            cout << "Not Enough Elements" << endl;
            return -9999;
        }
        return heap[0];
    }
};